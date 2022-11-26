# This the unix makefile to build j-alice with gnu make
# Right now its kinda silly, i'll make it fancier when i get a chance
# Author: Taras Glek
#
TARGETS=IrcResponder.o Element.o Handler.o Kernel.o Main.o Match.o  Nodemaster.o Parser.o Socket.o ServerSocket.o StringTokenizer.o Substituter.o TemplateProcessor.o Utils.o HTTPProcessor.o TokenProxyListener.o SocketHandler.o Template.o PreParser.o Logger.o XmlSocketResponder.o AimlWriter.o SaxParser.o PredicateEngine.o TimeKeeper.o Stream.o 

TOCLEAN=$(TARGETS) jalice j-alice


CXXFLAGS = -fno-rtti -Wno-deprecated -g -DDATE_BUILT='"$(shell date +%D)"' $(FLAGS)
ifdef JAVASCRIPT
CXXFLAGS += -DENABLE_JAVASCRIPT -I$(dir $(JAVASCRIPT))  -I$(dir $(JAVASCRIPT))..
TARGETS += $(JAVASCRIPT)
endif

WIN_COMPILER_PREFIX = /home/taras/work/win32/gcc-win32/bin/i386-mingw32msvc
ifdef WIN32
MINGW = /usr/cross-tools
LDFLAGS +=  -L$(MINGW)/i386-mingw32msvc/lib -lwsock32
CXX = $(WIN_COMPILER_PREFIX)-g++
endif

WX = $(shell which wx-config 2> /dev/null)

ifneq ($(WX), )
	TARGETS += wxwindows.o
	ifndef WIN32
	CXXFLAGS += $(shell wx-config --cflags) -DGUI
	#todo make proper checks for the xrc lib
	LDFLAGS += $(shell wx-config --libs) /usr/lib/libwx_gtk_xrc-2.4.so
	else
	WXDIR = /home/taras/public_html/WxWindows-2.4.0
	CXXFLAGS += -DGUI -I$(WXDIR)/include/ -I$(WXDIR)-contribs/include --pipe -D_X86_=1 -DWIN32 -D_WIN32 -DWINVER=0x0400 -D__WIN95__ -D__GNUWIN32__ -D__WIN32__  -DSTRICT  -D__WXMSW__ -D__WINDOWS__
	LDFLAGS = $(WXDIR)-contribs/lib/libwxxrc.a $(WXDIR)/lib/libwxmswu.a -lwsock32 -lgdi32 -lcomctl32 -lole32 -lcomdlg32 -luuid  -fvtable-thunks -Wl,--subsystem,windows -mwindows 
	TARGETS += rc.o
	endif
endif

all: j-alice 
j-alice: $(TARGETS) Makefile
	$(CXX) $(TARGETS) -o j-alice $(LDFLAGS)
#httpclient: Socket.o HttpClient.o Utils.o Logger.o SocketHandler.o TimeKeeper.o
#	$(CXX) Socket.o HttpClient.o Utils.o Logger.o SocketHandler.o TimeKeeper.o -o httpclient $(LDFLAGS)
clean:
	rm -f $(TOCLEAN)
Main.o: Main.cpp Config.h
rc.o: j-alice.rc j-alice.ico
	$(WIN_COMPILER_PREFIX)-windres --define __WIN32__ --define __WIN95__ --define __GNUWIN32__ --include-dir $(WXDIR)/include -i j-alice.rc -o rc.o
	
