ChatPanel=function(){var a=23,b=0,c=1,d=2,e=3,f=1e3,g=50,h=50,i="<BR/>",j=266,k=10;this.initialize=function(a,b,c){$=a,_=this,ab=b,ob=c?!0:!1,mb=FaceUtil.snew($),l(),m(),q(),r(),s(),t(),W(kb)},this.setChatTarget=function(a){var b=$.getImgr().getRoleRes();a!=b.name&&P(CHAT_TARGET.PLAYER,a)},this.insertMsg=function(a){w(a)},this.getSize=function(){return{cx:j,cy:jb.hs[kb]}},this.setPosition=function(a,b){ob||TQ.setDomPos(ab,a,b)},this.appendMsgToCurChannel=function(a){var b=bb.channeltabs.getActiveTab(),c=M(),d=M();a=C(0,CHAT_SYSPLAYER.SYS,"",c,0,"",d,b,a),V(b,a)},this.sendMessageToCurChannel=function(a){var b=Y();b!=""&&(a=Z(b)+a),U(a)};var l=function(){nb[CHAT_TAG.WORLD]="#FEC200",nb[CHAT_TAG.SYS]="#FFC200",nb[CHAT_TAG.STATE]="#FEFE00",nb[9900001]=nb[CHAT_TAG.STATE],nb[9900002]=nb[CHAT_TAG.STATE],nb[9900003]=nb[CHAT_TAG.STATE],nb[CHAT_TAG.ALLIANCE]="#00FE00",nb[CHAT_TAG.PRIVATE]="#FE80FE"},m=function(){var a=$.getGUI();a.initPanel(ab,uicfg.chatpanel,bb),cb=a.createPanelUIBack(ab,db);var b=TQ.getDomWidth(ab),c=TQ.getDomHeight(ab);a.setUIBack(cb,b,c,db.type),bb.facebtn=FacePanelBtn.snew($,bb.facebtn),bb.facebtn.setCaller({self:_,caller:v}),bb.sendbtn.setCaller({self:_,caller:A}),bb.largebtn.setCaller({self:_,caller:B}),bb.target.setCaller({self:_,caller:x}),TQ.addEvent(bb.msginput,"keydown",function(a){a=a?a:window.event;var b=TQ.getKeyCode(a);b==VK_KEY.RETURN?(Q(),TQ.preventDefault(a)):b==VK_KEY.UPARROW?(o(),TQ.preventDefault(a)):b==VK_KEY.DOWNARROW&&(p(),TQ.preventDefault(a))}),TQ.saveTextareaPos(bb.msginput),TQ.maxLength(bb.msginput,h),P(CHAT_TARGET.STATE,rstr.chatpanel.targetmenus[CHAT_TARGET.STATE])},n=function(a){if(a=="")return;TQ.find(lb.list,null,a)&&TQ.removeElement(lb.list,TQ.getLastFindIdx()),lb.list.push(a),lb.list.length>k&&TQ.removeElement(lb.list,0),lb.curpos=lb.list.length-1},o=function(){var a=lb.list[lb.curpos];a&&(bb.msginput.value=a),lb.curpos--,lb.curpos<0&&(lb.curpos=0)},p=function(){lb.curpos++,lb.curpos>=lb.list.length&&(lb.curpos=lb.list.length-1);var a=lb.list[lb.curpos];a&&(bb.msginput.value=a)},q=function(){TQ.isMobile()?(eb=new Menu($,{width:94,className:"mb_chattarget_menu_panel"}),a=39):eb=new Menu($,{width:51,className:"chattarget_menu_panel"});for(var b=0;b<rstr.chatpanel.targetmenus.length;++b)eb.addMenuItem({id:b,icon:null,text:rstr.chatpanel.targetmenus[b]});eb.setCaller({self:_,caller:y})},r=function(){var a=bb.channeltabs;for(var b=0;b<rstr.chatpanel.tabs.length;++b)a.setTabText(b,rstr.chatpanel.tabs[b]);a.setCaller({self:_,caller:u}),a.activeTab(0)},s=function(){for(var a=0;a<CHAT_CHANNEL.MAX;++a){ib[a]=ChatConScroller.snew($);var b=a==CHAT_CHANNEL.WORLD?bb.speakercon:bb.channeltabs.getTabItems(a).con;ib[a].initScroller(b,f,g)}},t=function(){$.regEvent(EVT.NET,NETCMD.CHAT,_,L)},u=function(a){fb=a},v=function(a){w(a.face)},w=function(a){TQ.setFocus(bb.msginput);if(bb.msginput.value.length+a.length>h)return;TQ.insertAtCursor(bb.msginput,a)},x=function(){var b=bb.target.getDom(),c=TQ.domOffset(b);eb.show({x:c.left-1,y:c.top-a*eb.getCount()-2})},y=function(a){$.getGUI().hideAllMenu(),a==e?z():P(a,rstr.chatpanel.targetmenus[a])},z=function(){var a=UIM.getDlg("inputtext");a.openDlg(rstr.chatpanel.playername,JVALID.getMaxUserLen());var b=function(a){JVALID.checkUsername(a)?P(CHAT_TARGET.PLAYER,a):UIM.getPanel("sysmsg").append(0,rstr.chatpanel.errname)};a.setCaller({self:_,caller:b})},A=function(){Q()},B=function(){kb=(kb+1)%jb.hs.length,W(kb)},C=function(a,b,c,d,e,f,g,h,j){H(b)||(j=TQ.decodeMessageForChat(j)),j=HyperLinkMgr.formatLink(j),j=mb.faceFormat(j);var k=D(d),l=D(g),m=H(b)?"":HyperLinkMgr.formatChatName(b,c)+'<font class="ui-chat-player-colon">:</font>';CHAT_CHANNEL.PRIVATE==h&&e!=0&&(m=HyperLinkMgr.formatChatName(b,c)+'<font class="ui-chat-player-splitword">对</font>'+l+HyperLinkMgr.formatChatName(e,f)+'<font class="ui-chat-player-splitword">说</font><font class="ui-chat-player-colon">:</font>');var n="ui-chat-player-title";TQ.isIE6()||TQ.isIE7()||TQ.isIE8()?n="ui-chat_player-title-fixie":TQ.isMobile()&&(n="mb-ui-chat-player-title"),m!=""&&(m=k+'<div class="'+n+'">'+m+"</div>");var o=I(a,b,h,n),p=J(a,b,h);return o+m+TQ.formatColorStr(j,p,"vertical-align:middle;")+i},D=function(a){var b="";return a?(b+=F(a),b+=G(a),b+=E(a),b):b},E=function(a){var b="";return a.vip>0&&(b=IMG.makeVipChatTagDiv(a.vip)),b},F=function(a){var b="";return g_platform!="3366"?b:(a.blue.grow>0&&(b=IMG.makeBlueGrowChatTagDiv(a.blue.grow)),b)},G=function(a){var b="";if(g_platform!="3366")return b;var c="<div style=\"float:left;height:17px;width:{0}px;BACKGROUND:url('{1}') 1px 3px no-repeat;\"></div>";return a.blue.level>0&&a.blue.super_?b+=TQ.format(c,16,IMG.makeBlueDiamondImg("high",a.blue.level)):a.blue.level>0&&(b+=TQ.format(c,16,IMG.makeBlueDiamondImg("comm",a.blue.level))),a.blue.level>0&&a.blue.year?(b+=TQ.format(c,16,IMG.makeBlueDiamondYearImg("comm")),IMG.makeCommChatTagDiv("ui_chat_bluevipyeartag",b)):b!=""?IMG.makeCommChatTagDiv("ui_chat_blueviptag",b):b},H=function(a){return a<CHAT_SYSPLAYER.MAX},I=function(a,b,c,d){var e=K(a,b,c);return IMG.makeChatTagDiv(e)},J=function(a,b,c){var d=K(a,b,c);return nb[d]},K=function(a,b,c){var d=0;return H(b)?b==CHAT_SYSPLAYER.STATE?d=CHAT_TAG.STATE:b==CHAT_SYSPLAYER.ALLIANCE?d=CHAT_TAG.ALLIANCE:b==CHAT_SYSPLAYER.SYS&&(d=CHAT_TAG.SYS):c==CHAT_CHANNEL.STATE?d=a:c==CHAT_CHANNEL.ALLIANCE?d=CHAT_TAG.ALLIANCE:c==CHAT_CHANNEL.PRIVATE?d=CHAT_TAG.PRIVATE:c==CHAT_CHANNEL.WORLD&&(d=CHAT_TAG.WORLD),d},L=function(a){var b=a.data;if(N(b)){ib[CHAT_CHANNEL.WORLD].clear();return}if(!b.msg)return;b.fromInfo||(b.fromInfo=M());var c=0;b.toId&&(c=b.toId);var d="";b.toName&&(d=b.toName);var e=0;b.fromCityId&&(e=b.fromCityId);var f=M();b.toInfo&&(f=b.toInfo),b.fromId!=CHAT_SYSPLAYER.SYS&&(b.msg=b.msg.replace(/#\[A:/g,"*[A:"));var g=C(e,b.fromId,b.fromName,b.fromInfo,c,d,f,b.channel,b.msg);V(b.channel,g)},M=function(){return{vip:0,blue:{level:0,year:0,super_:0,grow:0}}},N=function(a){return H(a.fromId)&&a.channel==CHAT_CHANNEL.WORLD&&a.msg==""},O=function(){ib[CHAT_CHANNEL.WORLD].clear()},P=function(a,b){a==CHAT_TARGET.PLAYER?bb.msginput.value="/"+b+" ":(gb=a,bb.target.setText(b)),TQ.setFocus(bb.msginput),TQ.moveCaretEnd(bb.msginput)},Q=function(){var a=bb.msginput,b=TQ.trimRight(a.value);n(b);var c=Y();c!=""?a.value=Z(c):a.value="",TQ.setFocus(bb.msginput);if(b=="")return;if(R(b))return;U(b)},R=function(a){return S(a)?T(a)?!0:(X(a),!0):!1},S=function(a){return a.indexOf("//")==0&&$.getImgr().getGMFlag()>0},T=function(a){return a=="//testanim"?(UIM.openDlg("testanim"),!0):a=="//close"?($.closeG(),!0):!1},U=function(a){ChatSender.sendMsg($,gb,a)},V=function(a,b){a==CHAT_CHANNEL.WORLD&&ib[a].clear(),ib[a].append(b),a!=CHAT_CHANNEL.ALL&&a!=CHAT_CHANNEL.WORLD&&ib[CHAT_CHANNEL.ALL].append(b)},W=function(a){if(TQ.isMobile())return;var b=$.getWinSizer().getCurSize(),c=jb.hs[a],d=b.cy-c;TQ.setCSS(ab,"top",d+"px"),TQ.setDomHeight(ab,c),TQ.setDomHeight(bb.chatpanel,c),TQ.setDomHeight(cb,c);var e=c-jb.barh-3*jb.spaceh,f=e-70,g=bb.channeltabs.getTabParent();TQ.setDomHeight(g,f);for(var h=0;h<bb.channeltabs.getTabCount();++h){var i=bb.channeltabs.getTabPanel(h);TQ.setDomHeight(i,f);var j=bb.channeltabs.getTabItems(h);j.con.setSize(j.con.getWidth(),f-2*jb.spaceh)}var k=e+2*jb.spaceh;TQ.setCSS(bb.toolbar,"top",k+"px");var l=$.getGUI(),m=TQ.getDomWidth(ab),c=TQ.getDomHeight(ab);l.setUIBack(cb,m,c,db.type),kb=a},X=function(a){var b=a.split(" ");if(b.length==0)return;var c=b[0].substr(2,b[0].length-2),d="";for(var e=1;e<b.length;++e)d+=",p"+e+"=[["+b[e]+"]]";$.send(null,"{cmd="+NETCMD_GM+",name=[["+c+"]]"+d+"}")},Y=function(){var a=bb.msginput.value,b=/^\/(\S*)/,c=a.match(b);return c?c[1]:""},Z=function(a){return"/"+a+" "},$=null,_=null,ab=null,bb={},cb=null,db=uiback.dlg.chatpanel,eb=null,fb=0,gb=CHAT_TARGET.STATE,hb="",ib={},jb={hs:[240,360],spaceh:2,barh:56},kb=0,lb={list:[],curpos:0},mb=null,nb={},ob=!1;this.initialize.apply(this,arguments)},SysMsgPanel=function(){var a=100,b=10,c,d,e,f={},g=null,h,i=uiback.dlg.noborder,j,k=[];this.init=function(a,b){c=a,d=this,g=b,e=g.sysmsg,l()},this.append=function(a,b){m(a,b)},this.refresh=function(){f.con.refresh()};var l=function(){var h=c.getGUI();h.initPanel(e,uicfg.main.sysmsgpanel,f),TQ.fixIE6Png(e),j=ChatConScroller.snew(c),j.initScroller(f.con,a,b),TQ.isMobile()&&(g.expandSysMsgBtn.setCaller({self:d,caller:n}),g.collapseSysMsgBtn.setCaller({self:d,caller:o}),TQ.setCSS(g.expandSysMsgBtn.getParent(),"display","none"),TQ.setCSS(g.collapseSysMsgBtn.getParent(),"display","block"))},m=function(a,b){var c=IMG.makeChatTagDiv(a)+b+"<br/>";j.append(c)},n=function(){TQ.setCSS(e,"display","block"),TQ.setCSS(g.chat,"display","block"),TQ.setCSS(g.expandSysMsgBtn.getParent(),"display","none"),TQ.setCSS(g.collapseSysMsgBtn.getParent(),"display","block")},o=function(){TQ.setCSS(e,"display","none"),TQ.setCSS(g.chat,"display","none"),TQ.setCSS(g.expandSysMsgBtn.getParent(),"display","block"),TQ.setCSS(g.collapseSysMsgBtn.getParent(),"display","none")};this.init.apply(this,arguments)}