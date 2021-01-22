object Milionerzy: TMilionerzy
  Left = 212
  Top = 128
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Milionerzy'
  ClientHeight = 639
  ClientWidth = 1191
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Tlo: TImage
    Left = 0
    Top = 0
    Width = 1200
    Height = 638
  end
  object OdpA: TImage
    Left = 56
    Top = 448
    Width = 225
    Height = 45
    Cursor = crHandPoint
  end
  object OdpB: TImage
    Left = 536
    Top = 448
    Width = 225
    Height = 45
    Cursor = crHandPoint
  end
  object OdpC: TImage
    Left = 56
    Top = 528
    Width = 225
    Height = 45
    Cursor = crHandPoint
  end
  object OdpD: TImage
    Left = 536
    Top = 528
    Width = 225
    Height = 45
    Cursor = crHandPoint
    Visible = False
  end
  object A: TLabel
    Left = 72
    Top = 448
    Width = 209
    Height = 45
    Cursor = crHandPoint
    AutoSize = False
    Caption = '...'
    Color = clInactiveCaption
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindow
    Font.Height = -32
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Transparent = True
    Visible = False
    OnClick = AClick
  end
  object Pytanie: TImage
    Left = 136
    Top = 312
    Width = 550
    Height = 100
    Visible = False
  end
  object D: TLabel
    Left = 552
    Top = 528
    Width = 209
    Height = 45
    Cursor = crHandPoint
    AutoSize = False
    Caption = '...'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWhite
    Font.Height = -32
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Transparent = True
    Visible = False
    OnClick = DClick
  end
  object B: TLabel
    Left = 560
    Top = 448
    Width = 201
    Height = 45
    Cursor = crHandPoint
    AutoSize = False
    Caption = '...'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -32
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Transparent = True
    Visible = False
    OnClick = BClick
  end
  object C: TLabel
    Left = 72
    Top = 528
    Width = 209
    Height = 45
    Cursor = crHandPoint
    AutoSize = False
    Caption = '...'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindow
    Font.Height = -32
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Transparent = True
    Visible = False
    OnClick = CClick
  end
  object Pytanie1: TLabel
    Left = 152
    Top = 320
    Width = 513
    Height = 89
    Alignment = taCenter
    AutoSize = False
    Caption = '......'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -37
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    Transparent = True
    Visible = False
    WordWrap = True
  end
  object Image1: TImage
    Left = 888
    Top = 0
    Width = 300
    Height = 638
    Visible = False
  end
  object Znacznik: TImage
    Left = 960
    Top = 576
    Width = 10
    Height = 10
  end
  object koniec: TLabel
    Left = 944
    Top = 16
    Width = 193
    Height = 41
    Cursor = crHandPoint
    AutoSize = False
    Transparent = True
    Visible = False
    OnClick = koniecClick
  end
  object Autor: TLabel
    Left = 1088
    Top = 584
    Width = 81
    Height = 33
    Cursor = crHandPoint
    AutoSize = False
    Transparent = True
    Visible = False
    OnClick = AutorClick
  end
  object Kolo3Odp: TImage
    Left = 632
    Top = 8
    Width = 250
    Height = 300
  end
  object kolo1: TImage
    Left = 920
    Top = 72
    Width = 65
    Height = 41
    Cursor = crHandPoint
    Enabled = False
  end
  object kolo2: TImage
    Left = 1000
    Top = 72
    Width = 65
    Height = 41
    Cursor = crHandPoint
    Enabled = False
  end
  object kolo3: TImage
    Left = 1088
    Top = 72
    Width = 65
    Height = 41
    Cursor = crHandPoint
    Enabled = False
    OnClick = kolo3Click
  end
  object Start: TButton
    Left = 456
    Top = 464
    Width = 289
    Height = 65
    Cursor = crHandPoint
    Caption = 'Start'
    Font.Charset = ANSI_CHARSET
    Font.Color = clMenu
    Font.Height = -40
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = StartClick
  end
  object MediaPlayer1: TMediaPlayer
    Left = 8
    Top = 16
    Width = 253
    Height = 30
    Visible = False
    TabOrder = 1
  end
  object MediaPlayer2: TMediaPlayer
    Left = 8
    Top = 48
    Width = 253
    Height = 30
    Visible = False
    TabOrder = 2
  end
  object MediaPlayer3: TMediaPlayer
    Left = 8
    Top = 80
    Width = 253
    Height = 30
    Visible = False
    TabOrder = 3
  end
  object MediaPlayer4: TMediaPlayer
    Left = 8
    Top = 112
    Width = 253
    Height = 30
    Visible = False
    TabOrder = 4
  end
  object NowaGra: TButton
    Left = 24
    Top = 48
    Width = 129
    Height = 41
    Caption = 'Nowa Gra'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    Visible = False
    OnClick = FormCreate
  end
  object MediaPlayer5: TMediaPlayer
    Left = 8
    Top = 144
    Width = 253
    Height = 30
    Visible = False
    TabOrder = 6
  end
  object MuteButton: TButton
    Left = 24
    Top = 88
    Width = 129
    Height = 33
    Caption = 'Mute'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -23
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 7
    OnClick = MuteButtonClick
  end
  object MediaPlayer6: TMediaPlayer
    Left = 8
    Top = 176
    Width = 253
    Height = 30
    Visible = False
    TabOrder = 8
  end
  object ladowanie: TProgressBar
    Left = 8
    Top = 616
    Width = 873
    Height = 17
    Min = 0
    Max = 300
    Smooth = True
    Step = 1
    TabOrder = 9
    Visible = False
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 752
    Top = 200
  end
end
