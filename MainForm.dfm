object EditorForm: TEditorForm
  Left = 329
  Top = 0
  Caption = 'Stalker Location Editor'
  ClientHeight = 554
  ClientWidth = 533
  Color = clBtnFace
  Constraints.MinHeight = 500
  Constraints.MinWidth = 500
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  WindowState = wsMaximized
  OnClose = FormClose
  OnKeyPress = FormKeyPress
  OnMouseWheelDown = OutMouseWheelDown
  OnMouseWheelUp = OutMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 19
  object Splitter1: TSplitter
    Left = 350
    Top = 28
    Height = 506
    Align = alRight
    ExplicitLeft = 360
    ExplicitTop = 152
    ExplicitHeight = 100
  end
  object StatusBar: TStatusBar
    Left = 0
    Top = 534
    Width = 533
    Height = 20
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    Panels = <
      item
        Text = '0x0'
        Width = 60
      end
      item
        Text = 'X'
        Width = 52
      end
      item
        Text = 'Y'
        Width = 52
      end
      item
        Bevel = pbRaised
        Text = 'R'
        Width = 52
      end
      item
        Text = 'A'
        Width = 52
      end
      item
        Text = #1058#1072#1081#1083
        Width = 200
      end
      item
        Alignment = taRightJustify
        Text = #1087#1077#1088#1077#1088#1080#1089#1086#1074#1086#1082
        Width = 60
      end>
    UseSystemFont = False
    OnDblClick = StatusBarDblClick
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 533
    Height = 28
    ButtonHeight = 24
    ButtonWidth = 24
    DrawingStyle = dsGradient
    EdgeBorders = [ebTop, ebBottom]
    Flat = False
    HotTrackColor = 16048601
    Images = ButtonsImages
    List = True
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Transparent = False
    object NewBtn: TToolButton
      Left = 0
      Top = 0
      Action = FileNew
    end
    object OpenBtn: TToolButton
      Left = 24
      Top = 0
      Action = FileOpen
    end
    object SaveBtn: TToolButton
      Left = 48
      Top = 0
      Action = FileSave
      Marked = True
    end
    object ToolButton4: TToolButton
      Left = 72
      Top = 0
      Width = 8
      Caption = 'ToolButton4'
      ImageIndex = 3
      Style = tbsSeparator
    end
    object CellBtn: TToolButton
      Left = 80
      Top = 0
      Hint = #1054#1076#1080#1085#1086#1095#1085#1099#1081' '#1074#1099#1073#1086#1088' (X)|'#1042#1099#1073#1088#1072#1090#1100' '#1086#1076#1085#1091' '#1103#1095#1077#1081#1082#1091
      Caption = 'Action1'
      Grouped = True
      ImageIndex = 7
      Style = tbsCheck
      OnClick = RangeBtnClick
    end
    object RangeBtn: TToolButton
      Left = 104
      Top = 0
      Hint = #1052#1085#1086#1078#1077#1089#1090#1074#1077#1085#1085#1099#1081' '#1074#1099#1073#1086#1088' (X)|'#1042#1099#1073#1088#1072#1090#1100' '#1075#1088#1091#1087#1087#1091' '#1103#1095#1077#1077#1082' '
      Caption = 'Action1'
      Grouped = True
      ImageIndex = 8
      Style = tbsCheck
      OnClick = RangeBtnClick
    end
    object MovedBtn: TToolButton
      Left = 128
      Top = 0
      Hint = #1055#1077#1088#1077#1090#1072#1089#1082#1080#1074#1072#1085#1080#1077' '#1090#1072#1081#1083#1086#1074' (C)'
      Caption = 'MoveTool'
      Grouped = True
      ImageIndex = 20
      Style = tbsCheck
      OnClick = RangeBtnClick
    end
    object RulerBtn: TToolButton
      Left = 152
      Top = 0
      Hint = #1048#1079#1084#1077#1088#1080#1090#1077#1083#1100#1085#1072#1103' '#1083#1080#1085#1077#1081#1082#1072
      Caption = 'RulerBtn'
      Grouped = True
      ImageIndex = 18
      Style = tbsCheck
      OnClick = RangeBtnClick
    end
    object ToolButton5: TToolButton
      Left = 176
      Top = 0
      Width = 8
      Caption = 'ToolButton5'
      ImageIndex = 5
      Style = tbsSeparator
    end
    object DrawGridBtn: TToolButton
      Left = 184
      Top = 0
      Action = ADrawGrid
      Style = tbsCheck
    end
    object Grid40Btn: TToolButton
      Left = 208
      Top = 0
      Action = ADrawGrid40
    end
    object DrawAnomallyBtn: TToolButton
      Left = 232
      Top = 0
      Action = ADrawAnomally
      Style = tbsCheck
    end
    object DrawRadiationBtn: TToolButton
      Left = 256
      Top = 0
      Action = ADrawRadiation
      Style = tbsCheck
    end
    object DrawTrigBtn: TToolButton
      Left = 280
      Top = 0
      Action = ADrawTriggers
      Style = tbsCheck
    end
    object Scaler: TTrackBar
      Left = 304
      Top = 0
      Width = 150
      Height = 24
      Hint = #1052#1072#1089#1096#1090#1072#1073
      Max = 15
      TabOrder = 0
      TickMarks = tmBoth
      TickStyle = tsNone
      OnChange = ScalerChange
    end
  end
  object CategoryPanelGroup1: TCategoryPanelGroup
    Left = 353
    Top = 28
    Width = 180
    Height = 506
    VertScrollBar.Tracking = True
    Align = alRight
    BevelOuter = bvNone
    Constraints.MaxWidth = 700
    Constraints.MinWidth = 128
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    GradientBaseColor = clCream
    GradientColor = 16749885
    HeaderAlignment = taCenter
    HeaderFont.Charset = DEFAULT_CHARSET
    HeaderFont.Color = clWindowText
    HeaderFont.Height = -13
    HeaderFont.Name = 'Tahoma'
    HeaderFont.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 1
    object PanelTile: TCategoryPanel
      Top = 0
      Height = 212
      Caption = #1058#1072#1081#1083#1099
      Color = clActiveBorder
      TabOrder = 0
      OnExpand = PanelTileExpand
      object PTiles: TButtonGroup
        Left = 0
        Top = 0
        Width = 176
        Height = 186
        Align = alClient
        BevelOuter = bvNone
        BevelKind = bkSoft
        BevelWidth = 2
        BorderStyle = bsNone
        ButtonHeight = 22
        ButtonWidth = 22
        ButtonOptions = [gboFullSize, gboShowCaptions]
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = TileBtns
        Items = <
          item
            Caption = #1090#1072#1081#1083'0'
            ImageIndex = 0
          end
          item
            Caption = #1090#1072#1081#1083'1'
            ImageIndex = 1
          end>
        PopupMenu = PopupMenuTile
        ShowHint = True
        TabOrder = 0
        OnButtonClicked = PTilesButtonClicked
      end
    end
    object PanelSprites: TCategoryPanel
      Top = 212
      Height = 30
      Caption = #1057#1087#1088#1072#1081#1090#1099
      Collapsed = True
      TabOrder = 1
      OnExpand = PanelSpritesExpand
      object ScrollBox1: TScrollBox
        Left = 0
        Top = 0
        Width = 176
        Height = 0
        VertScrollBar.Tracking = True
        Align = alClient
        BorderStyle = bsNone
        Color = clMoneyGreen
        ParentColor = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnResize = ScrollBox1Resize
        object PSprites: TFlowPanel
          Left = 0
          Top = 0
          Width = 176
          Height = 53
          Align = alTop
          AutoSize = True
          Caption = 'PSprites'
          ShowCaption = False
          TabOrder = 0
          object DeleteSprite: TImage
            Left = 1
            Top = 1
            Width = 52
            Height = 51
            Hint = #1059#1076#1072#1083#1080#1090#1100' '#1091#1082#1072#1079#1072#1085#1085#1099#1081' '#1089#1087#1088#1072#1081#1090
            AutoSize = True
            Picture.Data = {
              0954506E67496D61676589504E470D0A1A0A0000000D49484452000000340000
              00330806000000D87D2B530000000473424954080808087C0864880000000970
              48597300000B1200000B1201D2DD7EFC00000016744558744372656174696F6E
              2054696D650030382F32392F303824213DDF0000001874455874536F66747761
              72650041646F62652046697265776F726B734FB31F4E000008B24944415478DA
              DD9A5B6F134714C78F9338380924E6969696943681102824E6265EB885ABE009
              212E02A9C579E6A1F413947E82D24FE054ED0B1248140921F100E11509C9455C
              4353150897102009B9DAB1677ACEEE8CF7EC7877BD36B4525969BCEBB5333BBF
              FD9FF39F33EB44A494F0316D91F702DAB8310552DE805BB77A3FD8889A9B9320
              441A5EBF4EFFB74004B378315D1C6068A807D2E9F787A2FEA4A49B348AFD76C3
              C848D950950111CCA24549387C182CA073E76CA83B772A87523063B3B330AFAA
              0AAA8418C5F7DDF0EE5D5950E5036DD8602B73E408C89A1A805C0E22D3D300E7
              CFDB50F7EF970F652B9D7A8B3013D81FF60A9F565743152945509393A1A1CA03
              221852E6D83100BCA0C48B433E6F350BEAC20580E1E11EE8EF0F0F45FDA13223
              D92C4C603FA83748549DA03E23A574F86532A1A0C20369658E1E052065F0E216
              10DE55A9A0AA08EAE245C084EE818181D2500A6614FB9824180411381EDDA2D8
              96F2F0CBE54A4285035ABF3E65B90FC144A30E0402D15E1F47B055CDCC005CBA
              64433D7EEC0FB568D11924F8610CFF66121B0791ECB896A02211A8D650520642
              950622185286C28C9421132010156E92E0E89C8224A86A82BA7C19E0CD9B1E18
              1C2C865AB830857D25DFE1E1E4F8781184F91E6F212CC37D35C0281E06420503
              AD5B672B73FCB895333A5F0ACAF090537B6A550495C9005CB902F0F66D0FBC78
              D1EB8289C5925389044C0D0E42B6BFDF357813CC6AF86773B07D89AD14943F10
              87516E064C09AD524129DA6B50FC4E15EE6B08EAEA551B6A78B8D782993B3739
              BD6913E027907BF204B2B76FDB10943F00CE5EC3D1B16AB5D8DA4A407903110C
              85D9891376CEA8C16A855C61C680349450E748A928415DBB465017A1A5E5E074
              7B3B6469B0F8796E7818B2376F1654D03092296336526A4500543150229182CE
              CE24ECDC69C328354C850AE1669C33C1AAF17C2D413D7C0833ADAD90513781BE
              2FD015676EDCB0405C10048CFB3CC1B1BD50C7316C2B7DA0DC4004D3D59584FD
              FB1D1065026086195746A9C63FE7AD5AF591C5EF10A460376006D5739981872A
              82C1E8CF09AA035B8D01E5002512DBA1B1B10F4E9D7260B409D060E92EB23CB1
              F674DE08373A2718BC60DF15FA9C5608CF91423486BC01632A64C211D06A5B25
              DACE6227DF172BB466CD4FB076ED693870C00DC4410C5328E49456841B848293
              4C11132A9B4E436E6CCC05224A34AD8E82E945981EFF1C5AB52A856049D8B7AF
              287F0A61C5AD5B1B030F33765EF09C52E769AFCF67D0E5F238170581709558FE
              14C1F8BB5C7B7B0A56AF4EC2DEBD4EAE18EAB8000CD584320CC1142B1801D66C
              D65EC165EEDDB3804C003377344C7B008C3F106D6D6D29E8E848C29E3D4E7819
              7BD784CAE1484D3570C94D40ED05CBAFEC8307902BA19061D7BE30C140B42D5B
              66437577174FA01E70AE5CE2B9621E2B852C20B4F3FCC484AF194805D3E66100
              E503D1B674694AAE5C99846DDB8A8D80ED81859E50B926B472147E2A07850A5F
              A1157AF408C4E464A032AD0E0C55E7BF040D375CB5BD64494A2C5F9E84AD5B8B
              D5F151C6A51273B80290DACFDCBD6BBFF7C89F08D8F55B5D4898F04074A1E6E6
              5ED1DC7C3242E1876B146ECDAE9063AA68B538804B213285FBF73D8D40C3C4CA
              80290BC8DA162CB89E8BC7774476ED02492B560603864D4B235F0A6640F59A52
              2A373A0A39ACB8CD3023986515C0940F148F3761E77DB34D4D09320AC0859767
              88B15CE31005380534FBEA15E4DEBC2952E80B6CF5F615CFE0F57E0C3FC07281
              9A9AE298DDD7F3F17842503E69956890DAA67598A95249B2501386C36506066C
              38703B9C56A82EC482AE72A0C6C638767C5DA03A62FB762B8F809536C0129F87
              99F450888EC9AA679F3DF32D7708EAAB0AA0C201110C2A235019B96307481E6A
              DCE58C5C91DCD5E8989D9B7DFA14042ED5832653826AB3C32F34546920052329
              CC08C67438BAFBBAC6634A1499017B6FA9F3FC79A87207E3C0AA10102AADA046
              2B079A37CF0A334961460B3EAD0C2B79F8EC0F0110DC1C28D4F24A9D30D53529
              D51112CA1F88609432926C5AE58C5990163523CCCCFCB1ACFAF5EB92D5355749
              43D1FAA7A1049437D0DCB9B6320A06589809FE1CC103421AF9C32754AAB4ADDC
              D1CF0E7C80F23E60147E5FD3F002A08A81140C5A744262A5AD0DC05CEF80E966
              7C396E82E889F4E54BC84F4D15C1945A9D9A509D01506E2082C13083F9F36D65
              5835C09FF6F08173100E67DAB44023C8E1441A64044120BC51A1DAE503E50035
              34D8CA10CCEEDD56987915A2423FCAF2B1662F87A330CD51A8A9A73A6157A75E
              50FAF6FB413940F5F5D7519D1D70E810C858CC7908C2D5601005472BA18E54A1
              468FAC820CC02B7FBCC0F846509BC17AF2D3673DF77601C5625D08D4870AC525
              D569CA08A47E9EE013662E458CC993CED70D0D412DAE7786F112B93242CD4F21
              BE7D0ED6C44BCAE00429FF28CEA168D4829254B3A9F2A6F0EB82E166900FAE0A
              685F8F307508431B6A0D430CCA6F75EA973BFA73BD7D02D6C312178CB7CB4522
              5D78C686DAB2A500051ED6CCCF99E14730313402A0F53F2D9BB1CF2CD6EB2F0D
              A8A087897EF9A360D20A66CCDFE50CA83C953D9B373BE1E7137AC208BD3ACC99
              028C7E98817DE26B1AA1E09982F2CB1FBF902B05E30FC4A072583144366CB0E7
              238F3003237F6204333EEE8671FA3C49E7E99787C1124A790196820906E25038
              3FC9CECE4261EAE57A04D580F34CCD98759DD378C19F7DFA2C403D51B915C6AE
              9B43C094067242A52F8BF3946C6BB32CDD9C73A835608D568D401066C9CCA0FE
              56507EE50E357A48B216E07614605B104C38207B00DB092A53530362C50A9073
              E6B814AA1F19090F6340CDE0CB5F4C29532182C1FAEDB75A29BF09D56DE8152B
              0E00BFD99BC57228DFDA0A321AB5E7191B6654C1FC1EAE3337D434BEFC09764E
              99CAAC2A03A63C207E57114AB4B4C01C2C34158C6B2EA814AA1F1CA56236CCAF
              5129BF2DABBBB2FF93440D800C22423FB5BF0F8CD1E714BE3CC046BF7A775400
              531990338033D80EBE378CD3E777F87A76CA06AA08A672A07F6B8B445240D6EC
              67F9FF3BA00FB07D7440FF00E2411F4FA9B99EE40000000049454E44AE426082}
            OnClick = DeleteSpriteClick
          end
        end
      end
    end
    object PanelAR: TCategoryPanel
      Top = 242
      Height = 30
      Caption = #1040#1085#1086#1084#1072#1083#1080#1080'\'#1056#1072#1076#1080#1072#1094#1080#1103
      Collapsed = True
      TabOrder = 2
      OnExpand = PanelARExpand
      ExpandedHeight = 260
      object AR0: TRadioButton
        Left = 20
        Top = 78
        Width = 113
        Height = 17
        Hint = '(q)'
        Caption = #1041#1077#1079#1086#1087#1072#1089#1085#1072#1103
        TabOrder = 0
        OnClick = AR0Click
      end
      object AR100: TRadioButton
        Left = 20
        Top = 101
        Width = 113
        Height = 17
        Hint = '(w)'
        Caption = #1054#1087#1072#1089#1085#1072#1103
        TabOrder = 1
        OnClick = AR100Click
      end
      object ARRandom: TRadioButton
        Left = 20
        Top = 125
        Width = 113
        Height = 17
        Hint = '(e)'
        Caption = #1042#1077#1088#1086#1103#1090#1085#1086#1089#1090#1100':'
        Checked = True
        TabOrder = 2
        TabStop = True
        OnClick = ARRandomClick
      end
      object Panel1: TPanel
        Left = 85
        Top = 149
        Width = 77
        Height = 29
        Margins.Left = 0
        BevelKind = bkTile
        BevelOuter = bvNone
        TabOrder = 3
        object ToolBar2: TToolBar
          Left = 0
          Top = 0
          Width = 73
          Height = 25
          Margins.Left = 0
          ButtonHeight = 24
          ButtonWidth = 24
          Caption = 'ToolBar2'
          EdgeOuter = esRaised
          Flat = False
          HotTrackColor = clBlue
          Images = ButtonsImages
          TabOrder = 0
          object ARSetBtn: TToolButton
            Left = 0
            Top = 0
            Action = ACursorSet
            Marked = True
          end
          object ARAddBtn: TToolButton
            Left = 24
            Top = 0
            Action = ACursorAdd
          end
          object ARDecBtn: TToolButton
            Left = 48
            Top = 0
            Action = ACursorDec
          end
        end
      end
      object AR: TRadioGroup
        Left = 0
        Top = 0
        Width = 176
        Height = 72
        Align = alTop
        ItemIndex = 0
        Items.Strings = (
          #1040#1085#1086#1084#1072#1083#1100#1085#1086#1089#1090#1100
          #1056#1072#1076#1080#1086#1072#1082#1090#1080#1074#1085#1086#1089#1090#1100)
        TabOrder = 4
        OnClick = ARClick
      end
      object ARPowerE: TEdit
        Left = 16
        Top = 149
        Width = 47
        Height = 27
        NumbersOnly = True
        TabOrder = 5
        Text = '20'
        OnChange = ARPowerEChange
      end
      object ARPower: TUpDown
        Left = 63
        Top = 149
        Width = 18
        Height = 27
        Associate = ARPowerE
        Position = 20
        TabOrder = 6
      end
    end
    object PanelTriggers: TCategoryPanel
      Top = 272
      Height = 30
      Caption = #1058#1088#1080#1075#1075#1077#1088#1099
      Collapsed = True
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnExpand = PanelTriggersExpand
      ExpandedHeight = 190
      object PTriggers: TButtonGroup
        Left = 0
        Top = 0
        Width = 176
        Height = 0
        Align = alClient
        BevelOuter = bvNone
        BevelKind = bkSoft
        BevelWidth = 2
        BorderStyle = bsNone
        ButtonHeight = 26
        ButtonWidth = 20
        ButtonOptions = [gboFullSize, gboShowCaptions]
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        Images = TriggersIm
        Items = <
          item
            Caption = #1086#1095#1080#1089#1090#1080#1090#1100
          end
          item
            Caption = #1058#1086#1095#1082#1072' '#1088#1077#1089#1087#1072#1074#1085#1072
            Hint = #1058#1086#1095#1082#1072' '#1088#1077#1089#1087#1072#1074#1085#1072' '#1084#1091#1090#1072#1085#1090#1086#1074' '#1080#1083#1080' '#1089#1090#1072#1083#1082#1077#1088#1086#1074
            ImageIndex = 1
          end
          item
            Caption = #1057#1090#1086#1103#1085#1082#1072
            Hint = #1055#1086#1079#1080#1094#1080#1103' '#1083#1072#1075#1077#1088#1103' '#1089#1090#1072#1083#1082#1077#1088#1086#1074' '#1080#1083#1080' '#1084#1091#1090#1072#1085#1090#1086#1074' '#1089' '#1088#1077#1089#1087#1072#1074#1085#1086#1084
            ImageIndex = 2
          end
          item
            Caption = #1055#1086#1076#1098#1105#1084
            Hint = #1055#1077#1088#1077#1084#1077#1097#1072#1077#1090' '#1085#1072#1074#1077#1088#1093' '#1082' '#1089#1087#1091#1089#1082#1091' '
            ImageIndex = 3
          end
          item
            Caption = #1057#1087#1091#1089#1082
            Hint = #1055#1077#1088#1077#1084#1077#1097#1072#1077#1090' '#1074#1085#1080#1079' '#1082' '#1087#1086#1076#1098#1105#1084#1091
            ImageIndex = 4
          end
          item
            Caption = #1062#1077#1085#1090#1088' '#1090#1072#1081#1085#1080#1082#1086#1074
            Hint = 
              #1057#1090#1086#1080#1084#1086#1089#1090#1100' '#1090#1072#1081#1085#1080#1082#1072' '#1074' '#1101#1090#1086#1081' '#1090#1086#1095#1082#1077' '#1084#1080#1085#1080#1084#1072#1083#1100#1085#1072', '#1095#1077#1084' '#1076#1072#1083#1100#1096#1077' '#1090#1077#1084' '#1094#1077#1085#1085#1077#1077 +
              ' '#1090#1072#1081#1085#1080#1082'.'
            ImageIndex = 5
          end
          item
            Caption = #1055#1077#1088#1077#1093#1086#1076
            Hint = #1047#1086#1085#1072' '#1074#1099#1093#1086#1076#1072' '#1080#1079' '#1083#1086#1082#1072#1094#1080#1080
            ImageIndex = 6
          end>
        PopupMenu = PopupMenuTile
        TabOrder = 0
        OnButtonClicked = PTriggersButtonClicked
      end
    end
  end
  object OutPanel: TPanel
    Left = 0
    Top = 28
    Width = 350
    Height = 506
    Align = alClient
    BevelKind = bkSoft
    Caption = 'OutPanel'
    TabOrder = 4
    OnResize = OutPanelResize
    object Out: TImage
      Left = 1
      Top = 1
      Width = 325
      Height = 481
      Align = alClient
      Enabled = False
      Stretch = True
      OnMouseDown = OutMouseDown
      OnMouseLeave = OutMouseLeave
      OnMouseMove = OutMouseMove
      OnMouseUp = OutMouseUp
      ExplicitLeft = 176
      ExplicitTop = 112
      ExplicitWidth = 105
      ExplicitHeight = 105
    end
    object ScrollWi: TScrollBar
      Left = 1
      Top = 482
      Width = 344
      Height = 19
      Align = alBottom
      Enabled = False
      PageSize = 0
      TabOrder = 0
      OnChange = ScrollWiChange
    end
    object ScrollHe: TScrollBar
      Left = 326
      Top = 1
      Width = 19
      Height = 481
      Align = alRight
      Enabled = False
      Kind = sbVertical
      PageSize = 0
      TabOrder = 1
      OnChange = ScrollHeChange
    end
  end
  object DebugPanel: TPanel
    Left = 80
    Top = 288
    Width = 249
    Height = 185
    BevelKind = bkSoft
    BevelOuter = bvNone
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Visible = False
    object DebugLabel: TLabel
      Left = 11
      Top = 5
      Width = 81
      Height = 18
      Caption = 'Debug Panel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clGreen
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object NullTile: TImage
      Left = 14
      Top = 75
      Width = 19
      Height = 15
      Picture.Data = {
        07544269746D617076010000424D760100000000000036000000280000000A00
        00000A0000000100180000000000400100000000000000000000000000000000
        0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFFFFFFFFFFFFFC0C0C0C0C0C0FFFFFFFFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0C0C0C0FFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFFC0C0C0FFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFC0C0C0C0C0C0C0C0C0C0C0C0C0C0C0FFFFFFFFFFFFFFFFFF
        0000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        0000}
      OnClick = NullTileClick
    end
    object Log: TMemo
      Left = 98
      Top = 0
      Width = 147
      Height = 181
      Align = alRight
      ScrollBars = ssBoth
      TabOrder = 0
      WordWrap = False
      OnKeyPress = OutKeyPress
    end
    object openTRIG: TCheckBox
      Left = 8
      Top = 29
      Width = 76
      Height = 17
      Caption = 'openTRIG'
      Checked = True
      State = cbChecked
      TabOrder = 1
      OnClick = openTRIGClick
    end
    object loadsprites: TButton
      Left = 0
      Top = 122
      Width = 75
      Height = 25
      Caption = 'loadsprites'
      TabOrder = 2
      OnClick = loadspritesClick
    end
    object BitBtn1: TBitBtn
      Left = 58
      Top = 75
      Width = 34
      Height = 25
      DoubleBuffered = True
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333444444
        33333333333F8888883F33330000324334222222443333388F3833333388F333
        000032244222222222433338F8833FFFFF338F3300003222222AAAAA22243338
        F333F88888F338F30000322222A33333A2224338F33F8333338F338F00003222
        223333333A224338F33833333338F38F00003222222333333A444338FFFF8F33
        3338888300003AAAAAAA33333333333888888833333333330000333333333333
        333333333333333333FFFFFF000033333333333344444433FFFF333333888888
        00003A444333333A22222438888F333338F3333800003A2243333333A2222438
        F38F333333833338000033A224333334422224338338FFFFF8833338000033A2
        22444442222224338F3388888333FF380000333A2222222222AA243338FF3333
        33FF88F800003333AA222222AA33A3333388FFFFFF8833830000333333AAAAAA
        3333333333338888883333330000333333333333333333333333333333333333
        0000}
      ModalResult = 4
      NumGlyphs = 2
      ParentDoubleBuffered = False
      TabOrder = 3
      OnClick = BitBtn1Click
    end
    object CBdoublebuf: TCheckBox
      Left = 0
      Top = 106
      Width = 97
      Height = 17
      Caption = #1044#1074#1086#1081#1085#1072#1103' '#1073#1091#1092#1077#1088#1080#1079#1072#1094#1080#1103
      Checked = True
      State = cbChecked
      TabOrder = 4
      OnClick = CBdoublebufClick
    end
    object CBTilesLog: TCheckBox
      Left = 0
      Top = 153
      Width = 97
      Height = 17
      Caption = #1058#1072#1081#1083#1099' '#1074' '#1083#1086#1075
      TabOrder = 5
    end
    object BitBtn2: TBitBtn
      Left = 194
      Top = 132
      Width = 26
      Height = 25
      Cancel = True
      DoubleBuffered = True
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        333333333333333333333333000033338833333333333333333F333333333333
        0000333911833333983333333388F333333F3333000033391118333911833333
        38F38F333F88F33300003339111183911118333338F338F3F8338F3300003333
        911118111118333338F3338F833338F3000033333911111111833333338F3338
        3333F8330000333333911111183333333338F333333F83330000333333311111
        8333333333338F3333383333000033333339111183333333333338F333833333
        00003333339111118333333333333833338F3333000033333911181118333333
        33338333338F333300003333911183911183333333383338F338F33300003333
        9118333911183333338F33838F338F33000033333913333391113333338FF833
        38F338F300003333333333333919333333388333338FFF830000333333333333
        3333333333333333333888330000333333333333333333333333333333333333
        0000}
      ModalResult = 2
      NumGlyphs = 2
      ParentDoubleBuffered = False
      TabOrder = 6
      OnClick = BitBtn2Click
    end
    object Button1: TButton
      Left = 8
      Top = 44
      Width = 36
      Height = 25
      Caption = #1083#1080#1089#1090
      TabOrder = 7
      OnClick = Button1Click
    end
    object spris: TButton
      Left = 50
      Top = 44
      Width = 42
      Height = 25
      Caption = 'spris'
      TabOrder = 8
      OnClick = sprisClick
    end
  end
  object MainMenu1: TMainMenu
    Images = ButtonsImages
    Left = 32
    Top = 48
    object NFile: TMenuItem
      Caption = '&'#1060#1072#1081#1083
      object NNew: TMenuItem
        Action = FileNew
      end
      object NOpen1: TMenuItem
        Action = FileOpen
      end
      object NSave: TMenuItem
        Action = FileSave
      end
      object NSaveAs: TMenuItem
        Action = FileSaveAs
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object NExport: TMenuItem
        Caption = #1069#1082#1089#1087#1086#1088#1090' '#1082#1072#1088#1090#1099
        Hint = 'Save Picture'
        OnClick = NExportClick
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object NExit: TMenuItem
        Action = FileExit
      end
    end
    object NEdit: TMenuItem
      Caption = '&'#1055#1088#1072#1074#1082#1072
      object NUndo: TMenuItem
        Action = AUndo
        Caption = '&'#1054#1090#1084#1077#1085#1080#1090#1100' '#1090#1072#1081#1083#1099
      end
      object NDebug: TMenuItem
        Caption = '&Debug'
        OnClick = NDebugClick
      end
      object NReplace: TMenuItem
        Caption = '&'#1040#1074#1090#1086#1079#1072#1084#1077#1085#1072' '#1090#1072#1081#1083#1086#1074
        OnClick = NReplaceClick
      end
      object NReplaceSel: TMenuItem
        Caption = #1040#1074#1090#1086#1079#1072#1084#1077#1085#1072' &'#1091#1082#1072#1079#1072#1085#1085#1086#1075#1086
        ShortCut = 16466
        OnClick = NReplaceSelClick
      end
    end
    object NRun: TMenuItem
      Caption = '&'#1047#1072#1087#1091#1089#1082
      object NInfo: TMenuItem
        Caption = '&'#1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1083#1086#1082#1072#1094#1080#1080
        OnClick = NInfoClick
      end
      object NTestAnom: TMenuItem
        Caption = '&'#1056#1072#1079#1084#1077#1089#1090#1080#1090#1100' '#1072#1085#1086#1084#1072#1083#1080#1080
        OnClick = NTestAnomClick
      end
    end
    object NHelp: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N1: TMenuItem
        Caption = #1044#1080#1079#1072#1081#1085' '#1076#1086#1082#1091#1084#1077#1085#1090': '#1051#1086#1082#1072#1094#1080#1080
      end
      object NAbout: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = NAboutClick
      end
    end
  end
  object ActionList1: TActionList
    Images = ButtonsImages
    Left = 176
    Top = 48
    object FileNew: TAction
      Category = 'File'
      Caption = '&'#1053#1086#1074#1099#1081
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1091#1102' '#1083#1086#1082#1072#1094#1080#1102
      ImageIndex = 0
      ShortCut = 16462
      OnExecute = FileNewExecute
    end
    object FileOpen: TFileOpen
      Category = 'File'
      Caption = '&'#1054#1090#1082#1088#1099#1090#1100'...'
      Dialog.DefaultExt = 'loc'
      Dialog.Filter = #1057#1090#1072#1083#1082#1077#1088#1089#1082#1080#1077' '#1083#1086#1082#1072#1094#1080#1080'|*.loc'
      Dialog.Options = [ofNoChangeDir, ofPathMustExist, ofFileMustExist, ofCreatePrompt, ofNoTestFileCreate, ofNoNetworkButton, ofNoDereferenceLinks, ofForceShowHidden]
      Dialog.OptionsEx = [ofExNoPlacesBar]
      Dialog.Title = #1054#1090#1082#1088#1099#1090#1100' '#1083#1086#1082#1072#1094#1080#1102
      Hint = #1054#1090#1082#1088#1099#1090#1100'|'#1054#1090#1082#1088#1099#1090#1100' '#1083#1086#1082#1072#1094#1080#1102
      ImageIndex = 1
      ShortCut = 16463
      OnAccept = FileOpenAccept
    end
    object FileSave: TAction
      Category = 'File'
      Caption = '&'#1057#1086#1093#1088#1072#1085#1080#1090#1100
      ImageIndex = 2
      ShortCut = 16467
      OnExecute = FileSaveExecute
    end
    object FileSaveAs: TFileSaveAs
      Category = 'File'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' &'#1050#1072#1082'...'
      Dialog.DefaultExt = 'loc'
      Dialog.Filter = #1057#1090#1072#1083#1082#1077#1088#1089#1082#1080#1077' '#1083#1086#1082#1072#1094#1080#1080'|*.loc'
      Dialog.Options = [ofOverwritePrompt, ofHideReadOnly, ofNoChangeDir, ofPathMustExist, ofCreatePrompt, ofNoTestFileCreate, ofNoNetworkButton, ofNoDereferenceLinks, ofForceShowHidden]
      Dialog.OptionsEx = [ofExNoPlacesBar]
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100'|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1083#1086#1082#1072#1094#1080#1102
      ImageIndex = 4
      OnAccept = FileSaveAsAccept
    end
    object FileExit: TFileExit
      Category = 'File'
      Caption = '&'#1042#1099#1093#1086#1076
      Hint = #1042#1099#1093#1086#1076'|'#1047#1072#1082#1088#1099#1090#1100' '#1088#1077#1076#1072#1082#1090#1086#1088
      ImageIndex = 6
    end
    object ARangeSelect: TAction
      Category = 'ToolBar'
      Caption = 'Action1'
      ShortCut = 88
      OnExecute = ARangeSelectExecute
    end
    object ADrawGrid: TAction
      Category = 'ToolBar'
      Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1089#1077#1090#1082#1091
      Hint = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1089#1077#1090#1082#1091
      ImageIndex = 9
      ShortCut = 16455
      OnExecute = ADrawGridExecute
    end
    object ADrawGrid40: TAction
      Category = 'ToolBar'
      Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1089#1077#1090#1082#1091' 40 '#1084#1077#1090#1088#1086#1074
      Hint = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1089#1077#1090#1082#1091' 40 '#1084#1077#1090#1088#1086#1074
      ImageIndex = 17
      ShortCut = 113
      OnExecute = ADrawGrid40Execute
    end
    object ADrawTriggers: TAction
      Category = 'ToolBar'
      Caption = 'ADrawTriggers'
      Hint = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1090#1088#1080#1075#1075#1077#1088#1085#1099#1077' '#1079#1086#1085#1099
      ImageIndex = 16
      ShortCut = 16468
      OnExecute = ADrawTriggersExecute
    end
    object ADrawAnomally: TAction
      Category = 'ToolBar'
      Caption = 'ADrawAnomally'
      Hint = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1072#1085#1086#1084#1072#1083#1100#1085#1099#1077' '#1086#1073#1083#1072#1089#1090#1080
      ImageIndex = 11
      ShortCut = 16449
      OnExecute = ADrawAnomallyExecute
    end
    object ADrawRadiation: TAction
      Category = 'ToolBar'
      Caption = 'ADrawRadiation'
      Hint = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1079#1086#1085#1099' '#1088#1072#1076#1080#1072#1094#1080#1080
      ImageIndex = 10
      ShortCut = 16466
      OnExecute = ADrawRadiationExecute
    end
    object ACursorSet: TAction
      Category = 'ToolBar'
      Caption = 'Action1'
      Checked = True
      ImageIndex = 13
      ShortCut = 65
      OnExecute = ACursorSetExecute
    end
    object ACursorAdd: TAction
      Category = 'ToolBar'
      Caption = 'ACursorAdd'
      ImageIndex = 14
      ShortCut = 83
      OnExecute = ACursorAddExecute
    end
    object ACursorDec: TAction
      Category = 'ToolBar'
      Caption = 'ACursorDec'
      ImageIndex = 15
      ShortCut = 68
      OnExecute = ACursorDecExecute
    end
    object AUndo: TAction
      Category = 'Edit'
      Caption = '&'#1054#1090#1084#1077#1085#1080#1090#1100
      ImageIndex = 12
      ShortCut = 16474
      OnExecute = AUndoExecute
    end
    object LoadVars: TAction
      Category = 'ToolBar'
      Caption = 'LoadVars'
    end
    object MoveTool: TAction
      Category = 'ToolBar'
      Caption = 'MoveTool'
      ImageIndex = 20
      ShortCut = 67
      OnExecute = MoveToolExecute
    end
  end
  object ButtonsImages: TImageList
    ShareImages = True
    Left = 248
    Top = 48
    Bitmap = {
      494C010115001900040010001000FFFFFFFFFF00FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000006000000001002000000000000060
      0000000000000000000000000000000000000000000000000000000000000000
      00005B90C50080B3E40080B3E4007EB1E20074A7D9006A9DCF00689BCD006C9F
      D00073A6D7005B8FC20000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000005F93
      C8008BBEED006C9FD10083B6E60081B4E40076A9DA006A9DCF00689BCD006C9F
      D10076A9DA005A90C40000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000005F94C80091C4
      F1008CBFED00598BBF008FC2EF0085B8E7007FB2E10078ABDC0077AADB0079AC
      DD0083B6E5005F94C80000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000006297CB0098CB
      F500669BCF005688BA009ACDF7009ACDF7009ACDF7009ACDF7009ACDF7009ACD
      F7009ACDF7006297CB0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000FF040000669B
      CF00FF0400005A8DC0009DD0F9008CBFED009DD0F90079ADDD009DD0F9006197
      CB009DD0F900669BCF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000C0C0C000C0C0
      C000C0C0C0006498CC00A0D3FA005186BA00A0D3FA005186BA00A0D3FA005186
      BA0097CBF400699ED10000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C0006DA1D400A3D6FC00568CC1009ACDF600568CC10077AEE100568C
      C1006DA1D4000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000C0C0C000C0C0
      C000C0C0C0006FA3D700A6D9FD005D92C7006FA3D700719FCE00C0C0C000FF04
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000C0C0C000C0C0
      C000C0C0C00072A6D900A8DBFE006397CD00C0C0C000C0C0C000C0C0C000FF04
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C00074A7DB00A0D4FA00699DD100C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000C0C0C000C0C0
      C000C0C0C000C0C0C00076A9DC00C0C0C000C0C0C000C0C0C000C0C0C000FF04
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000FF04
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000FF04
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000FF040000C0C0
      C000FF040000FF040000C0C0C000FF040000FF040000C0C0C000FF040000FF04
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF3300FFFF3300FF989898FFFF33
      00FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF33
      00FFFF3300FF989898FFFF3300FFFF3300FFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF000000006A8BB9003863A0004A63
      99003863A0004A6399003863A0004A6399003863A0004A6399003863A0004A63
      99003863A0004A6399003863A0006A8BB9000000000078787800CECECE000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FFFA00EBFFFA00EBFFFA00EBFFFA00
      EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFFFA00
      EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFF000000004470AD0086B1EB006791
      CD0081ACE6006791CD0081ACE6006791CD0081ACE6006791CD0081ACE6006791
      CD0081ACE6006C97D1005D88C5006086B90000000000D2D2D20091919100B4B4
      B400FCFCFC000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF3300FFFF3300FF989898FFFF33
      00FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF33
      00FFFF3300FF989898FFFF3300FFFF3300FF929292FF929292FF929292FFFA00
      EBFF929292FF929292FF929292FF929292FF929292FF929292FF929292FF9292
      92FF929292FFFA00EBFF929292FF929292FF000000005571A6006F9AD4007BA6
      E00083AEE80083AEE80083AEE80083AEE80083AEE80083AEE80083AEE8007BA6
      E0007FAAE4006390CD006B90C500EDF1F7000000000000000000BEBEBE00B9B9
      B9009A9A9A00EEEEEE0000000000B7B7E3003333AD006666BF00000000000000
      000000000000000000000000000000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFFFFFFFFFFFFFFFFFFFFFFFFFA58FFFFFA58FFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF000000005784C20086B1EA007DA8
      E2005784C2005784C2005784C2005784C2005784C2005A86C40075A0DC0082AD
      E6006793D1007096CB00EEF2F800000000000000000000000000FCFCFC00AAAA
      AA00D8D8D800858585009797B8003333B3005555EE003333AA00000000000000
      000000000000000000000000000000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFFFFFFFFFFFFFFFFFFFFFFFFF3300FFFF4C1FFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF000000005B7AB000729DD70080AB
      E4005B88C5000000000000000000B5C9E5005E8AC70078A4DD0085B0E8006A97
      D3007399CD00EEF2F8000000000000000000000000000000000000000000F2F2
      F20098989800C4C4C4003333B9004B4BDC004F4FE8003333AB00000000000000
      000000000000000000000000000000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFFFFFFFFFFFFFFFFFFFFFFFFF3300FFFF4C1FFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF000000005F8BC8008CB7ED0083AE
      E6005F8BC80000000000B7CAE600628DCA007CA7DF0088B3E9006D99D600779C
      D000EEF2F9000000000000000000000000000000000000000000000000000000
      00009E9EC0003333C0007272EB003636CE004141D8003636B100000000000000
      000000000000000000000000000000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFFFFFFFFFFFFFFFFFFFFFFFFF3300FFFF4C1FFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF000000005F81B60076A1D90086B1
      E900628ECB00B8CCE7006390CD007EAAE3008BB6EC00709CD9007A9FD300EFF3
      F90000000000000000000000000000000000000000000000000000000000B7B7
      EC003333C6009B9BFE006060EE004949DC004747D5003B3BBD00B7B7E1000000
      000000000000000000000000000000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFFFFFFFFFFFFFFFFFFFFFFFFF3300FFFF4C1FFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF3300FF989898FFFF3300FFFFFFFFFF929292FF929292FF929292FFFA00
      EBFF929292FF929292FF929292FF929292FF929292FF929292FF929292FF9292
      92FF929292FFFA00EBFF929292FF929292FF000000006692CF0093BEF2008AB5
      EB006692CF006894D10081AEE5008FBAEE0073A0DB007DA2D600EFF3F9000000
      0000000000000000000000000000000000000000000000000000000000003333
      CC00A8A8FF008E8EFF008686FC007676F2005D5DEC005A5AE4003434AE00B7B7
      E10000000000000000000000000000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFD9CFFFFF8465FFFF3300FFFF3300FFFF4C1FFFFF4C1FFFFF8465FFFFD9
      CFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF000000006287BC007BA6DD008DB8
      EE006A95D30085B0E80092BDF10075A2DD007FA4D800EFF3FA00000000000000
      0000000000000000000000000000000000000000000000000000000000007F7F
      F1005555ED005555ED005353EC005050E6009C9CFF005D5DEC005A5AE4003939
      B9003636B1003333AB00B7B7E10000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFD9CFFFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFFD9
      CFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF000000006B97D30099C4F60090BB
      F00087B3EA0095C0F30078A5E00081A7DA00F0F4FA0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C3C3F8005555ED009C9CFF005D5DEC004343
      D5004C4CE4005656EF003333AB0000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFD9CFFFFFD9CFFFFFD9CFFFFFD9CFFFFFD9CFFFFFD9CFFFFFD9CFFFFFD9
      CFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF00000000658AC1007EA9DF0093BE
      F20098C3F4007BA8E10084A9DC00F0F4FA000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C3C3F8005151E8008080F9004F4F
      E1005454DC003B3BBD00B8B8E30000000000FF3300FFFF3300FF989898FFFF33
      00FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF33
      00FFFF3300FF989898FFFF3300FFFF3300FFFA00EBFFFA00EBFFFA00EBFFFA00
      EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFFFA00
      EBFFFA00EBFFFA00EBFFFA00EBFFFA00EBFF00000000709BD7009FCBF9009AC5
      F6007DABE30086ABDD00F0F4FA00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000005353EC008D8DFF009393
      FC004848D600BCBCEC000000000000000000989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF929292FF929292FF929292FFFA00
      EBFF929292FF929292FF929292FF929292FF929292FF929292FF929292FF9292
      92FF929292FFFA00EBFF929292FF929292FF00000000678EC50085B0E3007FAC
      E50088ACDF00F0F4FB0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000005555ED00A8A8FF005050
      E600C0C0F300000000000000000000000000FF3300FFFF3300FF989898FFFF33
      00FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF3300FFFF33
      00FFFF3300FF989898FFFF3300FFFF3300FFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF00000000759FDC0081AEE6008AAE
      E100F1F5FB000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C3C3F8005555ED00C2C2
      F80000000000000000000000000000000000FFFFFFFFFF3300FF989898FFFF33
      00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF3300FF989898FFFF3300FFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFA00
      EBFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFA00EBFFFFFFFFFFFFFFFFFF0000000099B9E5008BAFE100F1F5
      FB00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF040000FF040000C0C0C000FF040000FF040000C0C0C000FF040000FF04
      0000C0C0C000FF040000FF040000000000000000000000000000000000000000
      0000FF040000FF04000094949400FF040000FF04000094949400FF040000FF04
      000094949400FF040000FF040000000000000000000000000000000000000000
      0000FF040000FF040000C0C0C000FF040000FF040000C0C0C000FF040000FF04
      0000C0C0C000FF040000FF040000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF040000000000000000000000000000000000000000
      0000FF0400009494940094949400949494009494940094949400949494009494
      94009494940094949400FF040000000000000000000000000000000000000000
      0000FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF040000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000000000000000
      0000949494009494940094949400949494009494940094949400949494009494
      9400949494009494940094949400000000000000000000000000000000000000
      0000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF0400000000000000000000FF040000FF040000C0C0
      C000FF0400009494940094949400949494009494940000000000949494009494
      94009494940094949400FF0400000000000000000000FF040000FF0400009494
      9400FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF040000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF0400000000000000000000FF040000C0C0C000C0C0
      C000FF0400009494940094949400949494009494940000000000949494009494
      94009494940094949400FF0400000000000000000000FF040000949494009494
      9400FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF040000000000000000000000000000663300006633
      0000663300006633000066330000000000000000000000000000000000000000
      0000000000006666000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C0000000000000000000C0C0C000C0C0C000C0C0
      C000949494009494940094949400242424002424240000000000242424002424
      2400949494009494940094949400000000000000000094949400949494009494
      9400C0C0C000C0C0C000C0C0C000000000000000000000000000000000000000
      0000C0C0C000C0C0C000C0C0C000000000000000000000000000996600006666
      0000666600009966000000000000000000000000000000000000000000000000
      0000000000006666000000000000000000000000000000000000000000000000
      0000FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF0400000000000000000000FF040000C0C0C000C0C0
      C000FF0400009494940094949400949494009494940000000000949494009494
      94009494940094949400FF0400000000000000000000FF040000949494009494
      9400FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF040000000000000000000000000000996600006666
      000099660000CC99660000000000000000000000000000000000000000000000
      0000000000006666000000000000000000000000000000000000000000000000
      0000FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF0400000000000000000000FF040000C0C0C000C0C0
      C000FF0400009494940094949400949494009494940000000000949494009494
      94009494940094949400FF0400000000000000000000FF040000949494009494
      9400FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF040000000000000000000000000000996600009966
      0000CC99660066660000CC996600000000000000000000000000000000000000
      0000CC9966006666000000000000000000000000000000000000000000000000
      0000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C0000000000000000000C0C0C000C0C0C000C0C0
      C000949494009494940094949400949494009494940094949400949494009494
      9400949494009494940094949400000000000000000094949400949494009494
      9400C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000000000000000000000996600000000
      000000000000CC9966006666000066660000CC9966000000000000000000CC99
      660066660000CC99660000000000000000000000000000000000000000000000
      0000FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF0400000000000000000000FF040000C0C0C000C0C0
      C000FF0400009494940094949400949494009494940094949400949494009494
      94009494940094949400FF0400000000000000000000FF040000949494009494
      9400FF040000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000FF040000000000000000000000000000000000000000
      0000000000000000000000000000CC9966006666000066660000666600006666
      0000CC9966000000000000000000000000000000000000000000000000000000
      0000FF040000FF040000C0C0C000FF040000FF040000C0C0C000FF040000FF04
      0000C0C0C000FF040000FF0400000000000000000000FF040000C0C0C000C0C0
      C000FF040000FF04000094949400FF040000FF04000094949400FF040000FF04
      000094949400FF040000FF0400000000000000000000FF040000949494009494
      9400FF040000FF040000C0C0C000FF040000FF040000C0C0C000FF040000FF04
      0000C0C0C000FF040000FF040000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000000000000094949400949494009494
      9400949494009494940094949400949494009494940094949400949494009494
      9400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000FF04
      00000000000000000000000000000000000000000000FF040000949494009494
      940094949400949494009494940094949400949494009494940094949400FF04
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FF040000FF040000C0C0
      C000FF040000FF040000C0C0C000FF040000FF040000C0C0C000FF040000FF04
      00000000000000000000000000000000000000000000FF040000FF0400009494
      9400FF040000FF04000094949400FF040000FF04000094949400FF040000FF04
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF0000FFFF989898FF0000FFFFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000009376760000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF00EAE9FF989898FF00EA
      E9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EA
      E9FF00EAE9FF989898FF00EAE9FF00EAE9FF0000FFFF0000FFFF989898FF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF989898FF0000FFFF0000FFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000937676000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000929292FF929292FF929292FF9292
      92FF929292FF929292FF929292FF929292FF929292FF929292FF929292FF9292
      92FF929292FF929292FF929292FF929292FF00EAE9FF00EAE9FF989898FF00EA
      E9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EA
      E9FF00EAE9FF989898FF00EAE9FF00EAE9FF0000FFFF0000FFFF989898FF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF989898FF0000FFFF0000FFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000937676009376
      760000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFF00EAE9FF84FAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFF5C5CFFFF1212FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2828FFFF3737
      FFFF0000FFFF989898FF0000FFFFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000000000000937676009376
      760000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFF00EAE9FF84FAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFDEDEFFFF0101FEFF8989FFFFFFFFFFFFFFFFFFFFDEDEFFFF0101FEFFC0C0
      FFFF0000FFFF989898FF0000FFFFFFFFFFFF0000000000000000000000000000
      0000000000000000000000000000000000000000000093767600000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFF00EAE9FF84FAFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFFFFFFFFF3737FFFF0000FEFF0000FEFF0000FEFF0000FEFF1212FFFFFFFF
      FFFF0000FFFF989898FF0000FFFFFFFFFFFFFF040000FF040000C0C0C000FF04
      0000FF040000FF040000C0C0C000FF0400000000000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FFA5FFFFFFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFFFFFFFFFA3A3FFFF0101FEFFDEDEFFFFFFFFFFFF0A0AFFFF5C5CFFFFFFFF
      FFFF0000FFFF989898FF0000FFFFFFFFFFFFFF040000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000FF04000000000000000000000000
      000000000000000000000000000000000000929292FF929292FF929292FF9292
      92FF929292FF929292FF929292FF929292FF929292FF929292FF929292FF9292
      92FF929292FF929292FF929292FF929292FFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFF00EAE9FF84FAFAFFFFFFFFFFFFFFFFFF19ECEBFF00EBE9FFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFFFFFFFFFFFFFFFFF1212FFFF5C5CFFFFA3A3FFFF0101FEFFFFFFFFFFFFFF
      FFFF0000FFFF989898FF0000FFFFFFFFFFFFC0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C00000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFF00EAE9FF84FAFAFFFFFFFFFFFFFFFFFF34EEEDFF00EAE9FFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFFFFFFFFFFFFFFFFF5C5CFFFF1212FFFF4848FFFF3737FFFFFFFFFFFFFFFF
      FFFF0000FFFF989898FF0000FFFFFFFFFFFFFF040000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000FF04000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FFA5FFFFFFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFFFFFFFFFFFFFFFFFDEDEFFFF0101FEFF0404FFFFC0C0FFFFFFFFFFFFFFFF
      FFFF0000FFFF989898FF0000FFFFFFFFFFFFFF040000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000FF04000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF3737FFFF1212FFFFFFFFFFFFFFFFFFFFFFFF
      FFFF0000FFFF989898FF0000FFFFFFFFFFFFFF040000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000FF04000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF00EAE9FF989898FF00EA
      E9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EA
      E9FF00EAE9FF989898FF00EAE9FF00EAE9FF0000FFFF0000FFFF989898FF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF989898FF0000FFFF0000FFFFC0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C00000000000000000000000
      000000000000000000000000000000000000929292FF929292FF929292FF9292
      92FF929292FF929292FF929292FF929292FF929292FF929292FF929292FF9292
      92FF929292FF929292FF929292FF929292FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FF989898FF989898FF989898FF9898
      98FF989898FF989898FF989898FF989898FFFF040000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000FF04000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF00EAE9FF989898FF00EA
      E9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EAE9FF00EA
      E9FF00EAE9FF989898FF00EAE9FF00EAE9FF0000FFFF0000FFFF989898FF0000
      FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000
      FFFF0000FFFF989898FF0000FFFF0000FFFFFF040000FF040000C0C0C000FF04
      0000FF040000FF040000C0C0C000FF040000FF04000000000000000000000000
      000000000000000000000000000000000000FFFFFFFFFFFFFFFF929292FFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF929292FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00EAE9FF989898FF00EA
      E9FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF00EAE9FF989898FF00EAE9FFFFFFFFFFFFFFFFFF0000FFFF989898FF0000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFF0000FFFF989898FF0000FFFFFFFFFFFF0000000000000000000000000000
      000000000000000000000000000000000000849CB7005B7B9E005B7B9E005B7B
      9E005B7B9E00849CB70000000000000000000000000000000000000000000000
      000000000000000000000000000000000000A3A3A30084848400848484008484
      840084848400A3A3A300000000000000000000000000333C720075799C00DBDB
      E400FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000937676000000000000000000000000000000
      0000000000000000000000000000000000006682A6007B9EC60093B4D60093B4
      D60094B5D7006F8EB300CAD4E000000000000000000000000000000000000000
      0000000000000000000000000000000000008D8D8D00ACACAC00C0C0C000C0C0
      C000C1C1C10099999900D8D8D80000000000334983004174B8003A5D9C003542
      7A0075799D00DBDBE500EEEEEE00E5E5E500E5E5E500E5E5E500E5E5E500E5E5
      E500E5E5E500E5E5E500E5E5E500EFEFEF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000937676000000000000000000BBC6D4003D5A84007777
      770077777700777777007777770077777700777777003D5A84008FAFD1008DAD
      CF008DADCF006686B200A9B8CE000000000000000000CBCBCB00696969007E7E
      7E007E7E7E007E7E7E007E7E7E007E7E7E007E7E7E0069696900BCBCBC00BABA
      BA00BABABA0097979700C0C0C00000000000334E8A003F72B600225599003B6E
      B2003C5E9E0035437B005B608A0031366B0033386D0033386D0033386D003338
      6D0033386D0033386D00595C7D00E0E0E0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000937676000000000000000000C0CAD9004967910057759E00AEAB
      B8006885AD006885AD00AAA7B400AAA7B400AEABB8006885AD009AB6D80090AE
      D00090AED0008EABCF00899DBD00FEFEFE00CFCFCF007676760085858500BDBD
      BD009696960096969600B9B9B900B9B9B900BDBDBD0096969600C5C5C500BCBC
      BC00BCBCBC00BABABA00A9A9A900FEFEFE0033518D004174B8002C5FA3002D60
      A40023569A003D70B40033417900BEBEBE00D5D5D500D8D8D800DBDBDB00DCDC
      DC00DDDDDD00DDDDDD0033427900FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00009376760000000000000000000000000057759F008BA8D0006481A900B3B1
      B9006481A9006481A900AAA8B000AAA8B000B3B1B9006481A9008FB1CC0074B5
      A90094B0D2009EB7D900859ABE00E7EBF20083838300B9B9B90092929200C1C1
      C1009292920092929200B8B8B800B8B8B800C1C1C10092929200B9B9B900A0A0
      A000BFBFBF00C7C7C700A8A8A800EEEEEE00335391004477BB002C5FA3003568
      AC002B5EA2002E61A500334B8700BBBBBB00D3D3D300D5D5D500D8D8D800DBDB
      DB00DCDCDC00DDDDDD00334C8600FFFFFF0000000000FF040000FF040000C0C0
      C000FF040000FF040000C0C0C0000000000000000000C0C0C000000000009376
      7600000000000000000000000000000000005C7BA40089A6CE00607DA500BCBB
      C0004C6991004C699100B3B2B700B3B2B700BCBBC000607DA50062AC9A0058C8
      7F005BBF88009AB3D500899FC600C4CEDF0088888800B7B7B7008E8E8E00C9C9
      C9007A7A7A007A7A7A00C0C0C000C0C0C000C9C9C9008E8E8E00939393009C9C
      9C0099999900C3C3C300B0B0B000D4D4D40033569400477ABE002C5FA300376A
      AE002B5EA200376AAE0033508C00B8B8B800D0D0D000D3D3D300D5D5D500D8D8
      D800DBDBDB00DCDCDC0033508C00FFFFFF0000000000FF040000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000000000009376760000000000937676000000
      000000000000000000000000000000000000607EA8008CA9D1005C79A100C7C7
      C800C2C2C300C2C2C300C2C2C300C2C2C300BDC7BF0046927D0041C3650074EB
      92004BDB6A0070D09A00A6B9DD009FAECB008C8C8C00BABABA008A8A8A00D3D3
      D300CECECE00CECECE00CECECE00CECECE00CECECE00787878008E8E8E00BBBB
      BB009F9F9F00ACACAC00CCCCCC00B9B9B90033589700497CC00009336F002150
      90002B5EA200396CB00033529000B5B5B500CCCCCC00D0D0D000D3D3D300D5D5
      D500D8D8D800DBDBDB0033529000FFFFFF0000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C0000000000093767600937676009376760000000000C0C0
      C000000000000000000000000000000000006482AC0090ADD50059769E005875
      9D0058759D0058759D0058759D0057769C004191770038C55A006DE78A0073EA
      8F0082F3A20059E37C0061C28C00ABB8D2008F8F8F00BEBEBE00878787008686
      860086868600868686008686860085858500757575008A8A8A00B6B6B600BABA
      BA00C6C6C600A9A9A9009B9B9B00C2C2C200335A9A004C7FC300BBBBBB002251
      8C002C5FA3003B6EB20033559300B3B3B300C9C9C900CCCCCC00D0D0D000D3D3
      D300D5D5D500D8D8D80033569300FFFFFF0000000000FF040000C0C0C000C0C0
      C000C0C0C000C0C0C00000000000937676009376760093767600937676000000
      0000000000000000000000000000000000006785AE0093B0D8008AA7CF008AA7
      CF008AA7CF008AA7CF008AA7CF006CB0A60032C0560080F1A20083F2A10075ED
      90007FF3A20097FEBC0048E4670093F1A60092929200C1C1C100B8B8B800B8B8
      B800B8B8B800B8B8B800B8B8B8009A9A9A0085858500C4C4C400C6C6C600BDBD
      BD00C5C5C500D6D6D600A1A1A100C9C9C900335D9D005083C7001D5094003265
      A9002D60A4003D70B40033589700B0B0B000C7C7C700C9C9C900CCCCCC00D0D0
      D000D3D3D300D5D5D50033589700FFFFFF0000000000FF040000C0C0C000C0C0
      C000C0C0C0000000000093767600937676009376760093767600000000000000
      0000000000000000000000000000000000006A87B10097B4DC00E1DEEF00F3E5
      EF00F3E5EF00F3E5EF00F3E5EF0073D2840068D27C0081E4980059DB7C007DF4
      9B007EF6A10049C979006EEB870084F09A0095959500C5C5C500F2F2F200F8F8
      F800F8F8F800F8F8F800F8F8F800AEAEAE00A9A9A900BEBEBE00A6A6A600C4C4
      C400C6C6C60094949400B5B5B500C2C2C200335EA0005386CA00295CA0003F72
      B6003063A7003F72B600335A9A00AEAEAE00C4C4C400C7C7C700C9C9C900CCCC
      CC00D0D0D000D3D3D300335A9A00FFFFFF0000000000C0C0C000C0C0C000C0C0
      C000C0C0C0000000000093767600937676000000000000000000C0C0C000C0C0
      C000000000000000000000000000000000006D8BB4009AB7DF00F5E9F200EBDF
      E800EBDFE800EBDFE800EBDFE800CEDCD000E3DEE10077D788005DE3800088FA
      A8007AF49D00369D7700E0FBE500E9FCED0097979700C8C8C800FBFBFB00F1F1
      F100F1F1F100F1F1F100F1F1F100E1E1E100ECECEC00B3B3B300ACACAC00CDCD
      CD00C3C3C30074747400EFEFEF00F4F4F4003361A2005588CC00275A9E004174
      B8003164A8004174B800335D9E00ACACAC00C1C1C100C4C4C400C7C7C700C9C9
      C900CCCCCC00D0D0D000335D9D00FFFFFF0000000000FF040000C0C0C000C0C0
      C00000000000937676000000000000000000C0C0C000C0C0C000C0C0C000FF04
      000000000000000000000000000000000000708EB7009DBAE200F7EFF500ECE6
      EB00E1E5E200F0E7EE00E7E6E700E4E6E400BFE2C5005ADD74007EF4A10090FE
      B2005EDB8D00478B900000000000FDFFFD009B9B9B00CBCBCB0000000000F5F5
      F500EFEFEF00F7F7F700F2F2F200F1F1F100DCDCDC00A7A7A700C5C5C500D3D3
      D300A8A8A8007575750000000000FEFEFE003362A400588BCF001A4D91004376
      BA003265A9004376BA00335FA100AAAAAA00BFBFBF00C1C1C100C4C4C400C7C7
      C700C9C9C900CCCCCC00335FA000FFFFFF0000000000FF040000C0C0C000C0C0
      C0000000000000000000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000FF04
      0000000000000000000000000000000000007391BA00A1BEE600FAF5F900E7EF
      E900C5E7CC00B9E8C3008ED0A50068B5930088E99D007BF49D009AFFBF0078F8
      9B005CD18F006C9DAE0000000000000000009D9D9D00CFCFCF0000000000F7F7
      F700E2E2E200DCDCDC00BBBBBB009A9A9A00C4C4C400C3C3C300D8D8D800C4C4
      C400A2A2A2009494940000000000000000003364A7005D90D4003568AC00285B
      9F001A4D91004477BB003361A400A9A9A900BDBDBD00BFBFBF00C1C1C100C4C4
      C400C7C7C700C9C9C9003362A400FFFFFF0000000000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000000000000000000000000000000000007593BB00A3C0E800F2F9F300D7F4
      DE00C1F1CC00A7EFB9009EECAF00A0F5B7008DF5AA0099FFBB0083FBA7005EEE
      7D0082CCBC007495B90000000000000000009F9F9F00D1D1D10000000000F1F1
      F100E5E5E500D7D7D700D1D1D100D6D6D600CDCDCD00D8D8D800CBCBCB00B2B2
      B200B3B3B3009D9D9D0000000000000000007597C4003869AD004D7FC4005487
      CB003669AD0023569A003363A600A9A9A900BCBCBC00BDBDBD00BFBFBF00C1C1
      C100C4C4C400C7C7C7003363A600FFFFFF0000000000FF040000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000FF04
      0000000000000000000000000000000000007895BD00A9C6EE00E2F7E600D0F5
      D900C4F5D000C8F9D500B6F9C700B2FECB0099F9B4009AF9B6008AF4A200C0F8
      CC00A9C6EE007895BD000000000000000000A1A1A100D7D7D700F8F8F800EEEE
      EE00E8E8E800ECECEC00E3E3E300E4E4E400D5D5D500D5D5D500CBCBCB00E8E8
      E800D7D7D700A1A1A1000000000000000000FFFFFF00DBE4EF007597C400386A
      AD004E80C4005D90D4003365A900A0A0A000A9A9A900A9A9A900AAAAAA00ACAC
      AC00AEAEAE00B0B0B0003365A800FFFFFF0000000000FF040000FF040000C0C0
      C000FF040000FF040000C0C0C000FF040000FF040000C0C0C000FF040000FF04
      0000000000000000000000000000000000009BB1CF007997BF00C6BCC300B9BE
      B900B1C3B400A7C8AD0099D0A500A5D5B30095D3A30097CFA300AAC5AF00CBBC
      C7007997BF009BB1CF000000000000000000BABABA00A2A2A200C6C6C600C1C1
      C100C0C0C000BEBEBE00BCBCBC00C5C5C500BCBCBC00BBBBBB00BEBEBE00C8C8
      C800A2A2A200BABABA000000000000000000FFFFFF00FFFFFF00FFFFFF00DBE4
      EF007597C5003365A8003366AA003366AA003366AA003366AA003366AA003366
      AA003366AA003366AA00668CBF00FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000091ABC4006C8E
      B0006C8EB0006C8EB0006C8EB0006C8EB0006C8EB0006C8EB0006C8EB0006C8E
      B0006C8EB00091ABC40000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000007799BA00E1EA
      FD00DDE6FB00DCE5FB00DCE5FA00DBE4FA00DBE5FA00DAE3F900DAE4F900D9E4
      F900DFE9FC007799BA0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000BBC6D4003D5A
      84007777770077777700777777007777770077777700777777003D5A84003D5A
      84003D5A84003D5A84006E84A300000000000000000000000000CBCBCB006969
      69007E7E7E007E7E7E007E7E7E007E7E7E007E7E7E007E7E7E00696969006969
      690069696900696969009090900000000000000000000000000086A6C600DDE6
      FB00D4DCF600D3DBF500D2DBF500D1DAF400D0DAF400CED9F300CDD8F200CBD8
      F200D8E3F80086A6C6000000000000000000849CB7005B7B9E005B7B9E005B7B
      9E005B7B9E005B7B9E005B7B9E005B7B9E005B7B9E005B7B9E005B7B9E005B7B
      9E005B7B9E00849CB700000000000000000000000000C0CAD900496791005775
      9E00AEABB8006885AD006885AD00AAA7B400AAA7B400AEABB8006885AD007A97
      BF007794BC008DAAD200496791000000000000000000CFCFCF00767676008585
      8500BDBDBD009696960096969600B9B9B900B9B9B900BDBDBD0096969600A8A8
      A800A5A5A500BBBBBB00767676000000000000000000000000008DADCD00DCE5
      FB00D3DBF500D2DBF500D1DAF400D0DAF400CED9F300CDD8F200CBD8F200CAD7
      F100D7E3F8008DADCD0000000000000000006682A6007B9EC60093B4D60093B4
      D60093B4D60093B4D60093B4D60093B4D60093B4D60093B4D60093B4D60093B4
      D60094B5D7006F8EB300CAD4E000000000000000000057759F008BA8D0006481
      A900B3B1B9006481A9006481A900AAA8B000AAA8B000B3B1B9006481A9007A97
      BF006F8CB4008FACD40057759F00000000000000000083838300B9B9B9009292
      9200C1C1C1009292920092929200B8B8B800B8B8B800C1C1C10092929200A8A8
      A8009D9D9D00BDBDBD008383830000000000000000000000000091B1D000DCE5
      FA00D2DBF500D1DAF400D0DAF400CED9F300CDD8F200CBD8F200CAD7F100C8D6
      F000D6E1F70091B1D0000000000000000000728BAF006B8EBA008FAFD1008DAD
      CF008DADCF008DADCF008DADCF008DADCF008DADCF008DADCF008DADCF008DAD
      CF008DADCF00819DC300A9B8CE0000000000000000005C7BA40089A6CE00607D
      A500BCBBC0004C6991004C699100B3B2B700B3B2B700BCBBC000607DA5007A97
      BF006784AC0091AED6005C7BA400000000000000000088888800B7B7B7008E8E
      8E00C9C9C9007A7A7A007A7A7A00C0C0C000C0C0C000C9C9C9008E8E8E00A8A8
      A80095959500BFBFBF008888880000000000000000000000000095B3D200DBE4
      FA00D1DAF400D0DAF400CED9F300CDD8F200CBD8F200CAD7F100C8D6F000C7D5
      EF00D5E1F70095B3D2000000000000000000768EB200577AAC009AB6D80090AE
      D00090AED00090AED00090AED00090AED00090AED00090AED00090AED00090AE
      D00090AED00098B4D600899DBD00FEFEFE0000000000607EA8008CA9D1005C79
      A100C7C7C800C2C2C300C2C2C300C2C2C300C2C2C300C7C7C8005C79A1007A97
      BF005F7CA40094B1D900607EA80000000000000000008C8C8C00BABABA008A8A
      8A00D3D3D300CECECE00CECECE00CECECE00CECECE00D3D3D3008A8A8A00A8A8
      A8008D8D8D00C2C2C2008C8C8C0000000000000000000000000099B6D500DBE5
      FA00D0DAF400CED9F300CDD8F200CBD8F200CAD7F100C8D6F000C7D5EF00C5D5
      EF00D4E1F70099B6D50000000000000000007A91B4006081B20096B0D50094B0
      D20094B0D20094B0D20094B0D20094B0D20094B0D20094B0D20094B0D20094B0
      D20094B0D2009EB7D900859ABE00E7EBF200000000006482AC0090ADD5005976
      9E0058759D0058759D0058759D0058759D0058759D0058759D0059769E005976
      9E0059769E0098B5DD006482AC0000000000000000008F8F8F00BEBEBE008787
      8700868686008686860086868600868686008686860086868600878787008787
      870087878700C6C6C6008F8F8F000000000000000000000000009CBAD700DAE3
      F900CED9F300CDD8F200CBD8F200CAD7F100C8D6F000C7D5EF00C5D5EF00C1D3
      ED00D1DFF5009CBAD70000000000000000007D93B7007B98C40086A0CB0099B3
      D50098B2D40098B2D40098B2D40098B2D40098B2D40098B2D40098B2D40098B2
      D40098B2D4009AB3D500899FC600C4CEDF00000000006785AE0093B0D8008AA7
      CF008AA7CF008AA7CF008AA7CF008AA7CF008AA7CF008AA7CF008AA7CF008AA7
      CF008AA7CF0093B0D8006785AE00000000000000000092929200C1C1C100B8B8
      B800B8B8B800B8B8B800B8B8B800B8B8B800B8B8B800B8B8B800B8B8B800B8B8
      B800B8B8B800C1C1C100929292000000000000000000000000009FBCDA00DAE4
      F900CDD8F200CBD8F200CAD7F100C8D6F000C7D5EF00C5D5EF00C1D3ED00BCD0
      EA00CEDEF4009FBCDA0000000000000000008196B90093ADD400728DBD00BACC
      EE00BACCEE00BACCEE00BACCEE00BACCEE00BACCEE00BACCEE00BACCEE00BACC
      EE00BACCEE00BACCEE00A6B9DD009FAECB00000000006A87B10097B4DC00E1DE
      EF00F3E5EF00F3E5EF00F3E5EF00F3E5EF00F3E5EF00F3E5EF00F3E5EF00F3E5
      EF00E1DEEF0097B4DC006A87B100000000000000000095959500C5C5C500F2F2
      F200F8F8F800F8F8F800F8F8F800F8F8F800F8F8F800F8F8F800F8F8F800F8F8
      F800F2F2F200C5C5C50095959500000000000000000000000000A3BFDC00D9E4
      F900CBD8F200CAD7F100C8D6F000C7D5EF00C5D5EF00C1D3ED00BCD0EA00B6CE
      E800CCDDF300A3BFDC0000000000000000008498BB00A9BEE0006F8ABA005C7A
      AF005B79AE005A78AD005978AD005877AC005777AC005676AB005576AB005475
      AA005B7BB0004A679D008FA0C300ABB8D200000000006D8BB4009AB7DF00F5E9
      F200EBDFE800EBDFE800EBDFE800EBDFE800EBDFE800EBDFE800EBDFE800EBDF
      E800F5E9F2009AB7DF006D8BB400000000000000000097979700C8C8C800FBFB
      FB00F1F1F100F1F1F100F1F1F100F1F1F100F1F1F100F1F1F100F1F1F100F1F1
      F100FBFBFB00C8C8C80097979700000000000000000000000000A6C1DE00D8E2
      F800CAD7F100C8D6F000C7D5EF00C5D5EF00C1D3ED00BCD0EA00B6CEE800B3CC
      E600CCDDF200A6C1DE000000000000000000869ABD00ADC1E300A6B9DB00A5B8
      DA00A3B8DA00A1B7D900A0B6D8009EB5D7009CB4D6009AB3D50098B2D40096B1
      D300A4BCDE00869ABD00000000000000000000000000708EB7009DBAE200F7EF
      F500F0E7EE00F0E7EE00F0E7EE00F0E7EE00F0E7EE00F0E7EE00F0E7EE00F0E7
      EE00F7EFF5009DBAE200708EB70000000000000000009B9B9B00CBCBCB000000
      0000F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7F700F7F7
      F70000000000CBCBCB009B9B9B00000000000000000000000000A9C4E000D7E2
      F800C8D6F000C7D5EF00C5D5EF00C1D3ED00BCD0EA00B6CEE800B3CCE600B2CB
      E500CCDDF200A9C4E0000000000000000000899CBF00AFC2E400A7BADC00A6B9
      DB00A5B8DA00A3B8DA00A1B7D900A0B6D8009EB5D7009CB4D6009AB3D50098B2
      D400A6BEE000899CBF000000000000000000000000007391BA00A1BEE600FAF5
      F900F5F0F400F5F0F400F5F0F400F5F0F400F5F0F400F5F0F400F5F0F400F5F0
      F400FAF5F900A1BEE6007391BA0000000000000000009D9D9D00CFCFCF000000
      0000FEFEFE00FEFEFE00FEFEFE00FEFEFE00FEFEFE00FEFEFE00FEFEFE00FEFE
      FE0000000000CFCFCF009D9D9D00000000000000000000000000ABC6E100D7E3
      F800C7D5EF00C5D5EF00C1D3ED00BCD0EA00B6CEE800B3CCE60085A3C20085A3
      C20085A3C20085A6C60000000000000000008B9DC000B5C7E900B1C3E500B0C2
      E400AFC2E400AFC2E400AEC1E300A1B7D900A0B6D8009EB5D7009CB4D6009AB3
      D500B1C5E7008B9DC0000000000000000000000000007593BB00A3C0E800FEFB
      FD00FBF8FA00FBF8FA00FBF8FA00FBF8FA00FBF8FA00FBF8FA00FBF8FA00FBF8
      FA00FEFBFD00A3C0E8007593BB0000000000000000009F9F9F00D1D1D1000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D1D1D1009F9F9F00000000000000000000000000AEC8E200D6E2
      F700C5D5EF00C1D3ED00BCD0EA00B6CEE800B3CCE600B2CBE5009AB6D200E5EE
      FF00AEC8E200E2EBF5000000000000000000AAB7D1008D9FC2008D9FC2008D9F
      C2008D9FC2008D9FC2008D9FC200AFC2E400AEC1E300ADC1E300ACC0E200ABC0
      E2008D9FC200AAB7D1000000000000000000000000007895BD00A9C6EE000000
      0000FFFEFF00FFFEFF00FFFEFF00FFFEFF00FFFEFF00FFFEFF00FFFEFF00FFFE
      FF0000000000A9C6EE007895BD000000000000000000A1A1A100D7D7D7000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000D7D7D700A1A1A100000000000000000000000000B0C9E300DDE8
      FB00D4E2F700D1DFF500CEDEF400CCDDF300CCDDF200CCDDF200A7C1DC00B0C9
      E300E3ECF5000000000000000000000000000000000000000000000000000000
      00000000000000000000D7DDEA008FA0C3008FA0C3008FA0C3008FA0C3008FA0
      C300D7DDEA00000000000000000000000000000000009BB1CF007997BF00CBBC
      C700CBBCC700CBBCC700CBBCC700CBBCC700CBBCC700CBBCC700CBBCC700CBBC
      C700CBBCC7007997BF009BB1CF000000000000000000BABABA00A2A2A200C8C8
      C800C8C8C800C8C8C800C8C8C800C8C8C800C8C8C800C8C8C800C8C8C800C8C8
      C800C8C8C800A2A2A200BABABA00000000000000000000000000C5D8EB00B1CA
      E400B1CAE400B1CAE400B1CAE400B1CAE400B1CAE400B1CAE400B1CAE400E4ED
      F600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000600000000100010000000000000300000000000000000000
      000000000000000000000000FFFFFF00F003000000000000E003000000000000
      C003000000000000C00300000000000080030000000000008003000000000000
      8007000000000000800F000000000000800F000000000000800F000000000000
      800F000000000000800F000000000000800F000000000000800F000000000000
      800F000000000000FFFF00000000000000000000FFFFFFFF0000000080009FFF
      00000000800087FF000000008000C23F000000008001C03F000000008603E03F
      000000008407F03F00000000800FE01F00000000801FE00F00000000803FE001
      00000000807FFE010000000080FFFF010000000081FFFF830000000083FFFF87
      0000000087FFFF8F000000008FFFFFFFFFFFFFFFFFFFFFFFFFFFF001F001F001
      FFFFF001F001F001FFFFF001F001F001FFFFF00180018001FFFFF00180018001
      C1FBF00180018001C3FBF00180018001C3FBF00180018001C1F3F00180018001
      D863F00180018001FE07F00180018001FFFFFFFF800F800FFFFFFFFF800F800F
      FFFFFFFF800F800FFFFFFFFFFFFFFFFFFFFD000000000000FFF8000000000000
      FFD1000000000000FFC3000000000000FF87000000000000FF83000000000000
      FF0F000000000000003F000000000000007F000000000000007F000000000000
      007F000000000000007F000000000000007F000000000000007F000000000000
      007F000000000000007F000000000000FF03FF038000FFFCFF01FF010000FFF8
      800180010000FFF1000000000000FFE30000000000008007000000000000800F
      000000000000800F000000000000800F000000000000800F000000000000800F
      000000000000800F000220020000800F000320030000800F000320030000800F
      000300030000800F000300030000FFFFC003FFFFFFFFFFFFC003FFFFC001C001
      C003000380018001C003000180018001C003000180018001C003000080018001
      C003000080018001C003000080018001C003000080018001C003000080018001
      C003000380019009C003000380019009C003000380019FF9C003000390099FF9
      C007FC0780018001C00FFFFFFFFFFFFF}
  end
  object Tiles: TImageList
    AllocBy = 8
    Height = 256
    Masked = False
    Width = 256
    Left = 24
    Top = 136
  end
  object PopupMenuTile: TPopupMenu
    Left = 448
    Top = 176
    object NTilesNames: TMenuItem
      Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1085#1072#1079#1074#1072#1085#1080#1103' '#1090#1072#1081#1083#1086#1074
      OnClick = NTilesNamesClick
    end
  end
  object PopupMenuOut: TPopupMenu
    Left = 104
    Top = 48
    object NCurrTile: TMenuItem
      Caption = #1058#1072#1081#1083':'
      OnClick = NCurrTileClick
    end
    object NPrewTile: TMenuItem
      Caption = #1058#1072#1081#1083':'
      ShortCut = 16452
      OnClick = NPrewTileClick
    end
    object N6: TMenuItem
      Action = AUndo
      Caption = '&'#1054#1090#1084#1077#1085#1080#1090#1100' '#1090#1072#1081#1083
    end
    object NCopy: TMenuItem
      Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1085#1080#1077' 1'
      OnClick = NCopyClick
    end
  end
  object TriggersIm: TImageList
    AllocBy = 8
    DrawingStyle = dsTransparent
    Height = 10
    Width = 10
    Left = 304
    Top = 104
    Bitmap = {
      494C01010700090008000A000A00FFFFFFFFFE00FFFFFFFFFFFFFFFF424D3600
      000000000000360000002800000028000000140000000100200000000000800C
      000000000000000000000000000000000000FAFAFA00FF000000FF000000FF00
      0000FAFAFA00FAFAFA00FF000000FAFAFA00FAFAFA00FF000000FF00AE00FF00
      AE00FFBAE600FFBAE600FFFFFF00FFFFFF00FFBAE600FFBAE600FF00AE00FF00
      AE00FFFFFF00918D66006C6833006C6833006C6833006C6833006C6833006C68
      3300918D6600FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF000000FF7A7A00FF000000FF7A
      7A00FF000000FAFAFA00FF000000FF000000FF000000FF000000FFFFFF00FFFF
      FF00FF00AE00FF00AE00FFBAE600FFBAE600FF00AE00FF00AE00FFFFFF00FFFF
      FF00FFFFFF00766A3300BA874300BF8C4800C7945000CC995500C6934F00BB88
      4400766A3300FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF000000FAFAFA00FF000000FAFA
      FA00FF000000FAFAFA00FF000000FAFAFA00FAFAFA00FF000000FFFFFF00FFFF
      FF00FFBAE600FFBAE600FF00AE00FF00AE00FFBAE600FFBAE600FFFFFF00FFFF
      FF00FFFFFF00826C3300B6833F0095621E00A26F2B0095621E00A26F2B00B683
      3F00826C3300FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FAFAFA00FAFAFA00FF000000FAFA
      FA00FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FFBAE600FFBA
      E600FF00AE00FF00AE00FFFFFF00FFFFFF00FF00AE00FF00AE00FFBAE600FFBA
      E600FFFFFF008A6F3300B8854100A3702C00AB783400A16E2A00AB783400B885
      41008A6F3300FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FAFAFA00FAFAFA00FF000000FAFA
      FA00FAFAFA00FAFAFA00FF000000FAFAFA00FAFAFA00FF000000FF00AE00FF00
      AE00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF00AE00FF00
      AE00FFFFFF008D6F3300BB884400A3702C00AD7A3600A26F2B006F450900BB88
      44008D6F3300FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FAFAFA00FAFAFA00FF000000FAFA
      FA00FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0097723300C3904C00A26F2B00B27F3B00A3702D00BBBBBB00C390
      4C0097723300FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FAFAFA00FF000000FF000000FAFA
      FA00FAFAFA00FAFAFA00FF000000FAFAFA00FAFAFA00FF000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00A4753300D29F5B00915E1A00AA773300915E1A00AA773300D29F
      5B00A4753300FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF000000FF000000FAFAFA00FAFA
      FA00FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00A7763300D4A15D00915E1A009A672300915E1A009A672300D4A1
      5D00A7763300FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF000000FAFAFA00FAFAFA00FAFA
      FA00FAFAFA00FAFAFA00FFFFFF00FAFAFA00FAFAFA00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00A8753300DAA76300DDAA6600E5B26E00ECB97500E4B16D00DBA8
      6400A8753300FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FAFAFA00FAFAFA00FAFAFA00FAFA
      FA00FAFAFA00FAFAFA00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00BF996600AA773300AA773300AA773300AA773300AA773300AA77
      3300BF996600FFFFFF0000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FF00AE00FF00AE00FFBAE600FFBA
      E600FFFFFF00FFFFFF00FFBAE600FFBAE600FF00AE00FF00AE003000FF00C9BC
      FF003000FF006A48FF00FFFFFF00FFFFFF006A48FF003000FF00C9BCFF003000
      FF00FF000000FF000000FAFAFA00FAFAFA00FAFAFA00FAFAFA00FAFAFA00FAFA
      FA00FF000000FF000000FF000000FF000000FF000000FF000000FAFAFA00FAFA
      FA00FAFAFA00FAFAFA00FAFAFA00FAFAFA00FFFFFF00FFFFFF00FF00AE00FF00
      AE00FFBAE600FFBAE600FF00AE00FF00AE00FFFFFF00FFFFFF00C9BCFF000000
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000036FF00C9BC
      FF00FF000000FAFAFA00FAFAFA00FAFAFA00FAFAFA00FAFAFA00FAFAFA00FAFA
      FA00FAFAFA00FF000000FF000000FAFAFA00FAFAFA00FF000000FAFAFA00FAFA
      FA00FAFAFA00FAFAFA00FAFAFA00FF000000FFFFFF00FFFFFF00FFBAE600FFBA
      E600FF00AE00FF00AE00FFBAE600FFBAE600FFFFFF00FFFFFF003000FF00FFFF
      FF000000FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000036FF00FFFFFF003000
      FF00FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FF000000FF00
      0000FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FAFAFA00FAFA
      FA00FAFAFA00FAFAFA00FF000000FF000000FFBAE600FFBAE600FF00AE00FF00
      AE00FFFFFF00FFFFFF00FF00AE00FF00AE00FFBAE600FFBAE6006A48FF00FFFF
      FF00FFFFFF000000FF00FFFFFF00FFFFFF000036FF00FFFFFF00FFFFFF006A48
      FF00FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FAFAFA00FF00
      0000FAFAFA00FAFAFA00FF000000FAFAFA00FAFAFA00FF000000FAFAFA00FAFA
      FA00FAFAFA00FF000000FF000000FAFAFA00FF00AE00FF00AE00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FF00AE00FF00AE00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FAFAFA00FAFAFA00FF000000FF000000FAFAFA00FF000000FF000000FF00
      0000FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FAFAFA00FAFA
      FA00FAFAFA00FF000000FAFAFA00FAFAFA00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF000000FF000000FF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FAFAFA00FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FAFAFA00FF000000FAFAFA00FAFAFA00FF000000FAFAFA00FAFA
      FA00FAFAFA00FF000000FAFAFA00FAFAFA00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF006A48FF00FFFF
      FF00FFFFFF000036FF00FFFFFF00FFFFFF000000FF00FFFFFF00FFFFFF006A48
      FF00FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FF000000FF00
      0000FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FAFAFA00FAFA
      FA00FAFAFA00FF000000FAFAFA00FAFAFA00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF003000FF00FFFF
      FF000036FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF00FFFFFF003000
      FF00FAFAFA00FAFAFA00FAFAFA00FF000000FF000000FF000000FF000000FAFA
      FA00FAFAFA00FAFAFA00FF000000FAFAFA00FAFAFA00FF000000FAFAFA00FF00
      0000FAFAFA00FF000000FAFAFA00FF000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00C9BCFF000036
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF000000FF00C9BC
      FF00FF000000FAFAFA00FAFAFA00FAFAFA00FF000000FF000000FAFAFA00FAFA
      FA00FAFAFA00FF000000FF000000FF000000FF000000FF000000FAFAFA00FF00
      0000FF7A7A00FF000000FF7A7A00FF000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF003000FF00C9BC
      FF003000FF006A48FF00FFFFFF00FFFFFF006A48FF003000FF00C9BCFF003000
      FF00FF000000FF000000FAFAFA00FAFAFA00FAFAFA00FAFAFA00FAFAFA00FAFA
      FA00FF000000FF000000FF000000FAFAFA00FAFAFA00FF000000FAFAFA00FAFA
      FA00FF000000FF000000FF000000FAFAFA00}
  end
  object TileBtns: TImageList
    Height = 20
    Masked = False
    Width = 20
    Left = 280
    Top = 176
  end
  object SavePictureDialog1: TSavePictureDialog
    Left = 96
    Top = 136
  end
end
