//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
int rad1 = 30;
int rad2 = 30;
int midx, midy;
int circleCounter = 0;
double scale = 1;

struct pt {
    double x, y;
    pt operator- (pt p) {
        pt res = {x-p.x, y-p.y};
        return res;
    }
};

struct circle : pt {
    double r;
};

struct line {
    double a, b, c;
};

const double EPS = 1E-9;

double sqr(double a) {
    return a*a;
}

void drawCircle(circle c) {
    Form1->Image1->Canvas->Ellipse(c.x - c.r, c.y - c.r, c.x + c.r, c.y + c.r);
}

void drawLine(line l) {}

void tangents(pt c, double r1, double r2, vector<line> & ans) {
	double r = r2 - r1;
	double z = sqr(c.x) + sqr(c.y);
	double d = z - sqr(r);
	if (d < -EPS)  return;
	d = sqrt (abs (d));
	line l;
	l.a = (c.x * r + c.y * d) / z;
	l.b = (c.y * r - c.x * d) / z;
	l.c = r1;
	ans.push_back (l);
}
 
vector<line> tangents(circle a, circle b) {
	vector<line> ans;
	for (int i=-1; i<=1; i+=2)
		for (int j=-1; j<=1; j+=2)
			tangents (b-a, a.r*i, b.r*j, ans);
	for (size_t i=0; i<ans.size(); ++i)
		ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
	return ans;
}

circle cr1, cr2;

void drawing(int X, int Y, double scale) {
    if(circleCounter == 1) {
        cr2.x = X; cr2.y = Y; cr2.r = scale*rad2;
        drawCircle(cr1);
        drawCircle(cr2);

        Form1->Memo1->Lines->Add("x1 = " + FloatToStr(cr1.x));
        Form1->Memo1->Lines->Add("y1 = " + FloatToStr(cr1.y));
        Form1->Memo1->Lines->Add("r1 = " + FloatToStr(cr1.r));
        Form1->Memo1->Lines->Add("");
        Form1->Memo1->Lines->Add("x2 = " + FloatToStr(cr2.x));
        Form1->Memo1->Lines->Add("y2 = " + FloatToStr(cr2.y));
        Form1->Memo1->Lines->Add("r2 = " + FloatToStr(cr2.r));
        Form1->Memo1->Lines->Add("");

        vector<line> lines = tangents(cr1, cr2);
        for(int i = 0; i < 4; i++) {
            Form1->Memo1->Lines->Add("a" + IntToStr(i) + "=" + FloatToStr(lines[i].a));
            Form1->Memo1->Lines->Add("b" + IntToStr(i) + "=" + FloatToStr(lines[i].b));
            Form1->Memo1->Lines->Add("c" + IntToStr(i) + "=" + FloatToStr(lines[i].c));
            Form1->Memo1->Lines->Add("");
        }

        TColor colors[4];
        colors[0] = clBlue;
        colors[1] = clRed;
        colors[2] = clGreen;
        colors[3] = clFuchsia;

        for(int i = 0; i < 4; i++) {
            Form1->Image1->Canvas->Pen->Color = colors[i];
            pt dotich[2];
            dotich[0].x = 0;
            if(lines[i].b == 0)
                continue;
            dotich[0].y = - (lines[i].c + lines[i].a * dotich[0].x) / lines[i].b;
            dotich[1].x = midx*2;
            dotich[1].y = - (lines[i].c + lines[i].a * dotich[1].x) / lines[i].b;
            Form1->Image1->Canvas->MoveTo(dotich[0].x, dotich[0].y);
            Form1->Image1->Canvas->LineTo(dotich[1].x, dotich[1].y);
        }
        Form1->Image1->Canvas->Pen->Color = clBlack;
        circleCounter++;
    }
    else {
        circleCounter = 0;
        TRect bg(0, 0, Form1->Image1->Width, Form1->Image1->Height);
        Form1->Image1->Canvas->FillRect(bg);
        Form1->Memo1->Lines->Clear();

        cr1.x = X; cr1.y = Y; cr1.r = scale*rad1;
        drawCircle(cr1);
        circleCounter++;
    }
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    TRect bg(0, 0, Image1->Width, Image1->Height);
    Image1->Canvas->FillRect(bg);
    midx = Form1->Image1->Width / 2;
    midy = Form1->Image1->Height / 2;
}
//---------------------------------------------------------------------------
int nX = 0, nY = 0;
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    drawing(X, Y, scale);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
    rad1 = (Edit1->Text.Length() > 0 && StrToInt(Edit1->Text) > 0) ? StrToInt(Edit1->Text) : 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
    rad2 = (Edit1->Text.Length() > 0 && StrToInt(Edit2->Text) > 0) ? StrToInt(Edit2->Text) : 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    //TODO: drawing call
    scale += 0.1;
    Caption = scale;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    (scale > 1) ? scale -= 0.1 : 1;
    Caption = scale;
}
//---------------------------------------------------------------------------

