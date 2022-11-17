object Form_Create: TForm_Create
  Left = 304
  Top = 238
  BorderIcons = []
  BorderStyle = bsDialog
  Caption = #1053#1086#1074#1072#1103' '#1082#1072#1088#1090#1072
  ClientHeight = 57
  ClientWidth = 177
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnKeyPress = FormKeyPress
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 39
    Height = 13
    Caption = #1064#1080#1088#1080#1085#1072
  end
  object Label2: TLabel
    Left = 8
    Top = 32
    Width = 38
    Height = 13
    Caption = #1042#1099#1089#1086#1090#1072
  end
  object Edit_W: TEdit
    Left = 56
    Top = 8
    Width = 33
    Height = 21
    MaxLength = 3
    TabOrder = 0
    Text = '50'
    OnKeyPress = FormKeyPress
  end
  object Button_Create: TButton
    Left = 96
    Top = 8
    Width = 75
    Height = 21
    Cursor = crHandPoint
    Caption = #1057#1086#1079#1076#1072#1090#1100
    Default = True
    TabOrder = 2
    OnClick = Button_CreateClick
    OnKeyPress = FormKeyPress
  end
  object Button_Cancel: TButton
    Left = 96
    Top = 32
    Width = 75
    Height = 21
    Cursor = crHandPoint
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = Button_CancelClick
    OnKeyPress = FormKeyPress
  end
  object Edit_H: TEdit
    Left = 56
    Top = 32
    Width = 33
    Height = 21
    MaxLength = 3
    TabOrder = 1
    Text = '30'
    OnKeyPress = FormKeyPress
  end
end
