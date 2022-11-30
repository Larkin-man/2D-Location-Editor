object CreateForm: TCreateForm
  Left = 0
  Top = 0
  Caption = #1053#1086#1074#1072#1103' '#1083#1086#1082#1072#1094#1080#1103
  ClientHeight = 86
  ClientWidth = 271
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  Scaled = False
  DesignSize = (
    271
    86)
  PixelsPerInch = 96
  TextHeight = 19
  object BitBtn1: TBitBtn
    Left = 186
    Top = 8
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    DoubleBuffered = True
    Kind = bkOK
    ParentDoubleBuffered = False
    TabOrder = 0
  end
  object BitBtn2: TBitBtn
    Left = 186
    Top = 39
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    DoubleBuffered = True
    Kind = bkCancel
    ParentDoubleBuffered = False
    TabOrder = 1
    OnClick = BitBtn2Click
  end
  object LabeledEdit1: TLabeledEdit
    Left = 88
    Top = 8
    Width = 49
    Height = 27
    EditLabel.Width = 64
    EditLabel.Height = 19
    EditLabel.Caption = #1064#1080#1088#1080#1085#1072':'
    LabelPosition = lpLeft
    NumbersOnly = True
    TabOrder = 2
    Text = '3'
  end
  object LabeledEdit2: TLabeledEdit
    Left = 88
    Top = 41
    Width = 49
    Height = 27
    EditLabel.Width = 58
    EditLabel.Height = 19
    EditLabel.Caption = #1042#1099#1089#1086#1090#1072':'
    LabelPosition = lpLeft
    NumbersOnly = True
    TabOrder = 3
    Text = '3'
  end
  object H: TUpDown
    Left = 137
    Top = 41
    Width = 18
    Height = 27
    Associate = LabeledEdit2
    Max = 9999
    Position = 3
    TabOrder = 4
  end
  object W: TUpDown
    Left = 137
    Top = 8
    Width = 18
    Height = 27
    Associate = LabeledEdit1
    Max = 9999
    Position = 3
    TabOrder = 5
  end
end
