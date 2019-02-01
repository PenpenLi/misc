﻿#-*-coding:utf-8-*- 
import wx

try:
	##raise ImportError     # for testing the alternate implementation
	from wx import stc
	from StyledTextCtrl_2 import PythonSTC

	class CodeEditor(PythonSTC):
		def __init__(self, parent, style=wx.BORDER_NONE):
			PythonSTC.__init__(self, parent, -1, style=style)
			self.SetUpEditor()

		# Some methods to make it compatible with how the wxTextCtrl is used
		def SetValue(self, value):
			if wx.USE_UNICODE:
				value = value.decode('iso8859_1')
			val = self.GetReadOnly()
			self.SetReadOnly(False)
			self.SetText(value)
			self.EmptyUndoBuffer()
			self.SetSavePoint()
			self.SetReadOnly(val)

		def SetEditable(self, val):
			self.SetReadOnly(not val)

		def IsModified(self):
			return self.GetModify()

		def Clear(self):
			self.ClearAll()

		def SetInsertionPoint(self, pos):
			self.SetCurrentPos(pos)
			self.SetAnchor(pos)

		def ShowPosition(self, pos):
			line = self.LineFromPosition(pos)
			#self.EnsureVisible(line)
			self.GotoLine(line)

		def GetLastPosition(self):
			return self.GetLength()

		def GetPositionFromLine(self, line):
			return self.PositionFromLine(line)

		def GetRange(self, start, end):
			return self.GetTextRange(start, end)

		def GetSelection(self):
			return self.GetAnchor(), self.GetCurrentPos()

		def SetSelection(self, start, end):
			self.SetSelectionStart(start)
			self.SetSelectionEnd(end)

		def SelectLine(self, line):
			start = self.PositionFromLine(line)
			end = self.GetLineEndPosition(line)
			self.SetSelection(start, end)
		
		def SetUpEditor(self):
			"""
			This method carries out the work of setting up the demo editor.            
			It's seperate so as not to clutter up the init code.
			"""
			import keyword

			self.SetLexer(stc.STC_LEX_PYTHON)
			self.SetKeyWords(0, " ".join(keyword.kwlist))

			# Enable folding
			self.SetProperty("fold", "1" ) 

			# Highlight tab/space mixing (shouldn't be any)
			self.SetProperty("tab.timmy.whinge.level", "1")

			# Set left and right margins
			self.SetMargins(2,2)

			# Set up the numbers in the margin for margin #1
			self.SetMarginType(1, wx.stc.STC_MARGIN_NUMBER)
			# Reasonable value for, say, 4-5 digits using a mono font (40 pix)
			self.SetMarginWidth(1, 40)

			# Indentation and tab stuff
			self.SetIndent(4)               # Proscribed indent size for wx
			self.SetIndentationGuides(True) # Show indent guides
			self.SetBackSpaceUnIndents(True)# Backspace unindents rather than delete 1 space
			self.SetTabIndents(True)        # Tab key indents
			self.SetTabWidth(4)             # Proscribed tab size for wx
			self.SetUseTabs(False)          # Use spaces rather than tabs, or
			# TabTimmy will complain!    
			# White space
			self.SetViewWhiteSpace(False)   # Don't view white space

			# EOL: Since we are loading/saving ourselves, and the
			# strings will always have \n's in them, set the STC to
			# edit them that way.            
			self.SetEOLMode(wx.stc.STC_EOL_LF)
			self.SetViewEOL(False)

			# No right-edge mode indicator
			self.SetEdgeMode(stc.STC_EDGE_NONE)

			# Setup a margin to hold fold markers
			self.SetMarginType(2, stc.STC_MARGIN_SYMBOL)
			self.SetMarginMask(2, stc.STC_MASK_FOLDERS)
			self.SetMarginSensitive(2, True)
			self.SetMarginWidth(2, 12)

			# and now set up the fold markers
			self.MarkerDefine(stc.STC_MARKNUM_FOLDEREND,     stc.STC_MARK_BOXPLUSCONNECTED,  "white", "black")
			self.MarkerDefine(stc.STC_MARKNUM_FOLDEROPENMID, stc.STC_MARK_BOXMINUSCONNECTED, "white", "black")
			self.MarkerDefine(stc.STC_MARKNUM_FOLDERMIDTAIL, stc.STC_MARK_TCORNER,  "white", "black")
			self.MarkerDefine(stc.STC_MARKNUM_FOLDERTAIL,    stc.STC_MARK_LCORNER,  "white", "black")
			self.MarkerDefine(stc.STC_MARKNUM_FOLDERSUB,     stc.STC_MARK_VLINE,    "white", "black")
			self.MarkerDefine(stc.STC_MARKNUM_FOLDER,        stc.STC_MARK_BOXPLUS,  "white", "black")
			self.MarkerDefine(stc.STC_MARKNUM_FOLDEROPEN,    stc.STC_MARK_BOXMINUS, "white", "black")

			# Global default style
			if wx.Platform == '__WXMSW__':
				self.StyleSetSpec(stc.STC_STYLE_DEFAULT, 'fore:#000000,back:#FFFFFF,face:Courier New')
			elif wx.Platform == '__WXMAC__':
				# TODO: if this looks fine on Linux too, remove the Mac-specific case 
				# and use this whenever OS != MSW.
				self.StyleSetSpec(stc.STC_STYLE_DEFAULT, 'fore:#000000,back:#FFFFFF,face:Monaco')
			else:
				defsize = wx.SystemSettings.GetFont(wx.SYS_ANSI_FIXED_FONT).GetPointSize()
				self.StyleSetSpec(stc.STC_STYLE_DEFAULT, 'fore:#000000,back:#FFFFFF,face:Courier,size:%d'%defsize)

			# Clear styles and revert to default.
			self.StyleClearAll()

			# Following style specs only indicate differences from default.
			# The rest remains unchanged.

			# Line numbers in margin
			self.StyleSetSpec(wx.stc.STC_STYLE_LINENUMBER,'fore:#000000,back:#99A9C2')    
			# Highlighted brace
			self.StyleSetSpec(wx.stc.STC_STYLE_BRACELIGHT,'fore:#00009D,back:#FFFF00')
			# Unmatched brace
			self.StyleSetSpec(wx.stc.STC_STYLE_BRACEBAD,'fore:#00009D,back:#FF0000')
			# Indentation guide
			self.StyleSetSpec(wx.stc.STC_STYLE_INDENTGUIDE, "fore:#CDCDCD")

			# Python styles
			self.StyleSetSpec(wx.stc.STC_P_DEFAULT, 'fore:#000000')
			# Comments
			self.StyleSetSpec(wx.stc.STC_P_COMMENTLINE,  'fore:#008000,back:#F0FFF0')
			self.StyleSetSpec(wx.stc.STC_P_COMMENTBLOCK, 'fore:#008000,back:#F0FFF0')
			# Numbers
			self.StyleSetSpec(wx.stc.STC_P_NUMBER, 'fore:#008080')
			# Strings and characters
			self.StyleSetSpec(wx.stc.STC_P_STRING, 'fore:#800080')
			self.StyleSetSpec(wx.stc.STC_P_CHARACTER, 'fore:#800080')
			# Keywords
			self.StyleSetSpec(wx.stc.STC_P_WORD, 'fore:#000080,bold')
			# Triple quotes
			self.StyleSetSpec(wx.stc.STC_P_TRIPLE, 'fore:#800080,back:#FFFFEA')
			self.StyleSetSpec(wx.stc.STC_P_TRIPLEDOUBLE, 'fore:#800080,back:#FFFFEA')
			# Class names
			self.StyleSetSpec(wx.stc.STC_P_CLASSNAME, 'fore:#0000FF,bold')
			# Function names
			self.StyleSetSpec(wx.stc.STC_P_DEFNAME, 'fore:#008080,bold')
			# Operators
			self.StyleSetSpec(wx.stc.STC_P_OPERATOR, 'fore:#800000,bold')
			# Identifiers. I leave this as not bold because everything seems
			# to be an identifier if it doesn't match the above criterae
			self.StyleSetSpec(wx.stc.STC_P_IDENTIFIER, 'fore:#000000')

			# Caret color
			self.SetCaretForeground("BLUE")
			# Selection background
			self.SetSelBackground(1, '#66CCFF')

			self.SetSelBackground(True, wx.SystemSettings_GetColour(wx.SYS_COLOUR_HIGHLIGHT))
			self.SetSelForeground(True, wx.SystemSettings_GetColour(wx.SYS_COLOUR_HIGHLIGHTTEXT))

		def RegisterModifiedEvent(self, eventHandler):
			self.Bind(wx.stc.EVT_STC_CHANGE, eventHandler)


except ImportError:
	class CodeEditor(wx.TextCtrl):
		def __init__(self, parent):
			wx.TextCtrl.__init__(self, parent, -1, style =
				wx.TE_MULTILINE | wx.HSCROLL | wx.TE_RICH2 | wx.TE_NOHIDESEL)

		def RegisterModifiedEvent(self, eventHandler):
			self.Bind(wx.EVT_TEXT, eventHandler)

		def SetReadOnly(self, flag):
			self.SetEditable(not flag)
			# NOTE: STC already has this method

		def GetText(self):
			return self.GetValue()

		def GetPositionFromLine(self, line):
			return self.XYToPosition(0,line)

		def GotoLine(self, line):
			pos = self.GetPositionFromLine(line)
			self.SetInsertionPoint(pos)
			self.ShowPosition(pos)

		def SelectLine(self, line):
			start = self.GetPositionFromLine(line)
			end = start + self.GetLineLength(line)
			self.SetSelection(start, end)

modOriginal = 0
modModified = 1
modDefault = modOriginal

class CodePanel(wx.Panel):
    """Panel for the 'Demo Code' tab"""
    def __init__(self, parent, mainFrame):
        wx.Panel.__init__(self, parent, size=(1,1))
        if 'wxMSW' in wx.PlatformInfo:
            self.Hide()
        self.mainFrame = mainFrame
        self.editor = CodeEditor(self)
        self.editor.RegisterModifiedEvent(self.OnCodeModified)

        self.btnSave = wx.Button(self, -1, "Save Changes")
        self.btnRestore = wx.Button(self, -1, "Delete Modified")
        self.btnSave.Enable(False)
        self.btnSave.Bind(wx.EVT_BUTTON, self.OnSave)
        self.btnRestore.Bind(wx.EVT_BUTTON, self.OnRestore)

        self.radioButtons = { modOriginal: wx.RadioButton(self, -1, "Original", style = wx.RB_GROUP),
                              modModified: wx.RadioButton(self, -1, "Modified") }

        self.controlBox = wx.BoxSizer(wx.HORIZONTAL)
        self.controlBox.Add(wx.StaticText(self, -1, "Active Version:"), 0,
                            wx.RIGHT | wx.LEFT | wx.ALIGN_CENTER_VERTICAL, 5)
        for modID, radioButton in self.radioButtons.items():
            self.controlBox.Add(radioButton, 0, wx.EXPAND | wx.RIGHT, 5)
            radioButton.modID = modID # makes it easier for the event handler
            radioButton.Bind(wx.EVT_RADIOBUTTON, self.OnRadioButton)
            
        self.controlBox.Add(self.btnSave, 0, wx.RIGHT, 5)
        self.controlBox.Add(self.btnRestore, 0)

        self.box = wx.BoxSizer(wx.VERTICAL)
        self.box.Add(self.controlBox, 0, wx.EXPAND)
        self.box.Add(wx.StaticLine(self), 0, wx.EXPAND)
        self.box.Add(self.editor, 1, wx.EXPAND)
        
        self.box.Fit(self)
        self.SetSizer(self.box)


    # Loads a demo from a DemoModules object
    def LoadDemo(self, demoModules):
        pass


    def ActiveModuleChanged(self):
        self.UpdateControlState()
        self.mainFrame.pnl.Freeze()        
        self.mainFrame.pnl.Thaw()

        
    def LoadDemoSource(self, source):
        self.editor.Clear()
        self.editor.SetValue(source)
        self.JumpToLine(0)
        self.btnSave.Enable(False)


    def JumpToLine(self, line, highlight=False):
        self.editor.GotoLine(line)
        self.editor.SetFocus()
        if highlight:
            self.editor.SelectLine(line)
        
       
    def UpdateControlState(self):
        pass

                    
    def OnRadioButton(self, event):
        pass


    def ReloadDemo(self):
        pass

                
    def OnCodeModified(self, event):
        self.btnSave.Enable(self.editor.IsModified())

        
    def OnSave(self, event):
        pass


    def OnRestore(self, event): # Handles the "Delete Modified" button
        pass
