object Form1: TForm1
  Left = 236
  Top = 33
  Width = 815
  Height = 700
  Caption = #1055#1088'2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 16
    Width = 577
    Height = 625
    OnMouseDown = Image1MouseDown
  end
  object Label1: TLabel
    Left = 600
    Top = 24
    Width = 61
    Height = 20
    Caption = #1056#1072#1076#1110#1091#1089'1:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 600
    Top = 56
    Width = 61
    Height = 20
    Caption = #1056#1072#1076#1110#1091#1089'2:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 600
    Top = 88
    Width = 173
    Height = 40
    Alignment = taCenter
    Caption = #1062#1077#1085#1090#1088#1080' '#1082#1110#1083' '#1074#1089#1090#1072#1085#1086#1074#1110#1090#1100' '#1084#1080#1096#1077#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Edit1: TEdit
    Left = 664
    Top = 24
    Width = 89
    Height = 21
    TabOrder = 0
    Text = '30'
    OnChange = Edit1Change
  end
  object Memo1: TMemo
    Left = 600
    Top = 136
    Width = 185
    Height = 361
    TabOrder = 1
  end
  object Button1: TButton
    Left = 648
    Top = 616
    Width = 89
    Height = 25
    Caption = #1042#1080#1081#1090#1080
    TabOrder = 2
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 664
    Top = 56
    Width = 89
    Height = 21
    TabOrder = 3
    Text = '30'
    OnChange = Edit2Change
  end
end
