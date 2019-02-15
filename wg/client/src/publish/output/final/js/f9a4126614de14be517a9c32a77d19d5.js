ACTOR_ACTS_NAMEID={stand:1,attack:2,mattack:2,walk:3,hurt:4,die:5},EffectContainer=Class.extern(function(){var a=[];this.add=function(b){a.push(b)},this.remove=function(b){var c=function(a){this.isSatisfiedBy=function(b){return b.getId()==a}},d=TQ.find(a,null,null,new c(b));d&&(d.destory(),a.splice(TQ.getLastFindIdx(),1))},this.update=function(b,c){for(var d=0;d<a.length;++d){var e=a[d];e.setZIndex(b),e.setPosition(c),e.play()}},this.release=function(){for(var b=0;b<a.length;++b)a[b].destory();a=[]}}),NullProgressBar=Class.extern(function(){var a=0,b=0;this.isNull=!0,this.setPos=function(a){},this.setZOrder=function(a){},this.setVal=function(b){a=b},this.getVal=function(){return a},this.setMaxVal=function(a){b=a},this.getMaxVal=function(){return b}}),Actor=Class.extern(function(){var a=2e3,b=45,c=5,d=60,e=10,f=null,g=null,h=null,i=null,j="",k=null,l=null,m=null,n=null,o=null,p=null,q=null,r={x:0,y:0},s=NullState,t=NullPngAnim.snew(0),u=EffectContainer.snew(),v=NullProgressBar.snew(),w=null,x=1,y="",z=0;this.init=function(a){f=this,g=a,v.setMaxVal(100),v.setVal(100)},this.setParent=function(a){k=a},this.getParent=function(){return k},this.setId=function(a){h=a},this.getId=function(){return h},this.setType=function(a){i=a},this.getType=function(){return i},this.setName=function(a){j=a},this.getName=function(){return j},this.setCampName=function(a){y=a},this.getCampName=function(){return y},this.setIcon=function(a){z=a},this.getIcon=function(){return z},this.isHero=function(){return i==ACTOR_TYPE.HERO},this.isDef=function(){return i==ACTOR_TYPE.DEF},this.getEffectContainer=function(){return u},this.setResId=function(a){l=a},this.getResId=function(){return l},this.setDirection=function(a){n=a,A()},this.getDirection=function(){return n},this.setPosition=function(a){r.x=a.x,r.y=a.y,B()},this.getPosition=function(){return r},this.getZIndex=function(){return a+r.y},this.setAction=function(a){m=ACTOR_ACTS_NAMEID[a],A()},this.setState=function(a){s.end(),s=a,s.start()},this.getAnim=function(){return t},this.setObserver=function(a){w=a},this.isIdle=function(){return s.isIdle()},this.setHP=function(a,b){v.setMaxVal(a),v.setVal(b)},this.getMaxHP=function(){return v.getMaxVal()},this.getHP=function(){return v.getVal()},this.setUnitHP=function(a){x=a},this.getUnitHP=function(){return x},this.subHP=function(a){if(a<=0)return;var b=v.getVal(),c=Math.max(0,b-a);v.setVal(c),w(h,"subhp",b-c)},this.addHP=function(a){if(a<=0)return;var b=v.getMaxVal(),c=v.getVal(),d=Math.min(b,c+a);v.setVal(d),w(h,"addhp",d-c)},this.die=function(){w(h,"die"),u.release()},this.update=function(a){B(),s.update()},this.destory=function(){v.isNull||(g.getEntityfactory().freePBar(v),v=NullProgressBar.snew()),s.end(),t.stop(),u.release()};var A=function(){if(!C())return;D();if(t.getId()==g.getAnimMgr().makeAvatarAnimId(l,n,m))return;t.stop(),t=g.getAnimMgr().allocAvatar(f.getResId(),n,m,k),t.setPosition(r),t.play()},B=function(){t.setPosition(r);var c=a+r.y;t.setZIndex(c),u.update(c,r),v.setPos({x:r.x-b/2,y:r.y-d}),v.setZOrder(c+e)},C=function(){return isNull(k)?!1:isNull(l)?!1:isNull(m)?!1:isNull(n)?!1:!0},D=function(){if(!v.isNull)return;if(i!=ACTOR_TYPE.SOLDIER)return;var a=v.getMaxVal(),d=v.getVal();v=g.getEntityfactory().allocPBar(k),v.setSize({cx:b,cy:c}),v.setBarBorder(IMG.makeImg("comm/perbarbak45.gif")),v.setBarImage(IMG.makeImg("comm/perbar45.gif")),v.setZOrder(0),v.setVal(d),v.setMaxVal(a)}}),ActorManager=Class.extern(function(){var a=[],b=0;this.init=function(a){},this.add=function(b){a.push(b)},this.getById=function(b){if(isNull(b))return null;var d=c(b);return d<0?null:a[d]},this.remove=function(b){b.destory();var d=c(b.getId());a.splice(d,1)},this.clear=function(){for(var b=0;b<a.length;++b)a[b].destory();a=[]},this.getCount=function(){return a.length},this.getByIdx=function(b){return a[b]},this.update=function(){for(var b=0;b<a.length;++b)a[b].update()},this.getMainWallId=function(){return b},this.setMainWallId=function(a){b=a};var c=function(b){for(var c=0;c<a.length;++c)if(a[c].getId()==b)return c;return-1}}),FightMapDlg=Class.extern(function(){var a=null,b=null,c=null,d={},e=null,f=null,g=null;this.init=function(c){a=c,b=this},this.openDlg=function(b,c,d){if(!a.getImgr().getFightDemoRounds(b,c)){a.getGUI().msgBox(rstr.comm.msgts,rstr.fightMapDlg.notFindFightDemo,MB_F_CLOSE,null);return}h(),o(),p(b,c,d)},this.resize=function(a){c&&c.isShow()&&f.resize(c,d,a)},this.setHideCaller=function(a){g=a};var h=function(){if(c)return;i(),j(),k(),l(),m()},i=function(){c=Dialog.snew(a,{modal:!1,uiback:uiback.dlg.noborder,pos:{x:0,y:0}}),a.getGUI().initDlg(c,uicfg.military.fightmapdlg,d)},j=function(){f=FightMapDlgSizer.snew(a)},k=function(){var b=["attacker","defender"],c=[uicfg.military.fightmapdlg.t_[0],uicfg.military.fightmapdlg.t_[2]];for(var e=0;e<b.length;++e){var f=d[b[e]+"Role"];f.items={},a.getGUI().buildDomItems(f,c[e],null,f.items)}},l=function(){e=ShowFight.snew(a,c,d,f)},m=function(){c.setCaller({self:b,caller:q}),d.skipBtn.setCaller({self:b,caller:n})},n=function(){e.skip()},o=function(){c.show()},p=function(c,d,f){a.regUpdater(b,r,10),b.resize(a.getWinSizer().getValidClientSize()),e.initFight(c,d,f),b.resize(a.getWinSizer().getValidClientSize())},q=function(c){c==C_SYS_DLG_HIDE&&(a.unregUpdater(b,r),g&&g.caller.call(g.self))},r=function(){e.update()}}),FightMapDlgSizer=Class.extern(function(){var a=380,b=a/5,c=66,d=null,e=null,f=null,g=null;this.init=function(a){d=a},this.resize=function(a,b,c){h(a,b,c),i(),j(),k(),l(),m(),n(),o(),p()},this.resetHeroListPosition=function(){r(),q()};var h=function(a,b,c){e=a,f=b,g=c},i=function(){var a=e.getConDom();TQ.setDomSize(a,g.cx,g.cy),TQ.setDomSize(a.firstChild,g.cx,g.cy),e.refreshBack()},j=function(){var a=d.getWinSizer().getMaxClientSize(),b=(g.cx-a.cx)/2,c=(g.cy-a.cy)/2;TQ.setDomPos(f.map,b,c),TQ.setDomSize(f.map,a.cx,a.cy)},k=function(){var a=g.cx-TQ.getDomWidth(f.defenderRole);TQ.setCSS(f.defenderRole,"left",a+"px")},l=function(){var a=(g.cx-TQ.getDomWidth(f.HPProgBar))/2;TQ.setCSS(f.HPProgBar,"left",a+"px")},m=function(){q(),r()},n=function(){var a=g.cx-TQ.getDomWidth(f.defBar)-50,b=g.cy-c-TQ.getDomHeight(f.wallBar)-TQ.getDomHeight(f.defBar)-50;TQ.setDomPos(f.defBar,a,b)},o=function(){var a=g.cx-TQ.getDomWidth(f.wallBar)-50,b=g.cy-c-TQ.getDomHeight(f.wallBar)-50;TQ.setDomPos(f.wallBar,a,b)},p=function(){var a=(g.cx-131)/2,b=g.cy-40;TQ.setDomPos(f.skipBtn.getParent(),a,b)},q=function(){var a=0,b=g.cy-c;TQ.setDomPos(f.attackerHeroList.getParent(),a,b)},r=function(){var a=f.defenderHeroList.getCount(),d=g.cx-b*a,e=g.cy-c;TQ.setDomPos(f.defenderHeroList.getParent(),d,e)}}),ShowFight=Class.extern(function(){var a=null,b=null,c=null,d=null,e=null,f=null,g=null,h=null;this.init=function(f,g,i,j){a=f,b=g,c=i,h=j,d=ShowRounds.snew(f),e=ShowFightResult.snew(f,g,i)},this.initFight=function(b,c,d){e.initFight(b,c,d),i(a.getImgr().getFightDemoRounds(b,c))},this.update=function(){d.isEnd()?e.update():d.update()},this.skip=function(){d.skip()};var i=function(b){g=b,a.getActorMgr().clear(),j(b),k(b.attacker.actors),w("attacker",b.attacker.actors,1),w("defender",b.defender.actors,3),l("attacker",b.attacker),l("defender",b.defender),t("attacker"),t("defender"),u(),v(),d.setRounds(b.rounds)},j=function(a){var b=ItemResUtil.findItemres(a.mapId);d.setMapPosInfo(b.offsetPos,b.gridPixel),IMG.setBKImage(c.map,IMG.makeImg("map/"+b.img))},k=function(a){a[0].type==ACTOR_TYPE.HERO?f=ShowSingleHeroFight.snew():f=ShowSoldiersFight.snew()},l=function(a,b){m()?n(a,b):o(a,b),p(a),q(a)},m=function(){return a.getActorMgr().getCount()==2&&a.getActorMgr().getByIdx(0).getType()==ACTOR_TYPE.HERO},n=function(a,b){var d=c[a+"Role"],e=B(a)[0];IMG.setBKImage(d.items.icon,IMG.makeMidImg(e.getIcon())),TQ.setTextEx(d.items.name,e.getName()),TQ.setTextEx(d.items.alliance,""),TQ.setTextEx(d.items.fightCap,f.calcFightCap(b.actors)),TQ.setClass(d.items[a+"Bak"],a+"HeroBak")},o=function(a,b){var d=c[a+"Role"];IMG.setBKImage(d.items.icon,IMG.makeMidImg(b.role.icon)),TQ.setTextEx(d.items.name,b.role.name),TQ.setTextEx(d.items.alliance,b.role.alli),TQ.setTextEx(d.items.fightCap,f.calcFightCap(b.actors)),TQ.setClass(d.items[a+"Bak"],a+"RoleBak")},p=function(a){var b=c[a+"Role"];b.items.hpProgBar.setRange(r(a)),b.items.hpProgBar.setMirror(a=="defender")},q=function(a){var b=c[a+"Role"];b.items.hpProgBar.setValue(0,s(a))},r=function(a){var b=0;return C(a,function(a){if(a.getType()==ACTOR_TYPE.DEF)return;if(a.getType()==ACTOR_TYPE.WALL)return;b+=Math.floor(a.getMaxHP()/a.getUnitHP()+1e-5)}),b},s=function(a){var b=0;return C(a,function(a){if(a.getType()==ACTOR_TYPE.DEF)return;if(a.getType()==ACTOR_TYPE.WALL)return;b+=Math.floor(a.getHP()/a.getUnitHP()+1e-5)}),b},t=function(a){var b=0,d=c[a+"HeroList"];C(a,function(a){if(a.getType()!=ACTOR_TYPE.SOLDIER)return;var c=d.getItem(b++);IMG.setBKImage(c.exsubs.icon,IMG.makeSmallImg(a.getIcon()));var e=Math.floor(a.getHP()/a.getUnitHP()+1e-5),f=Math.floor(a.getMaxHP()/a.getUnitHP()+1e-5);TQ.setTextEx(c.exsubs.number,e+"/"+f),TQ.setTextEx(c.exsubs.number_bak,e+"/"+f)}),d.setItemCount(b),h.resetHeroListPosition()},u=function(){var a=y();a?(TQ.setCSS(c.wallBar,"display","block"),TQ.setTextEx(c.wallHP,a.getHP()+"/"+a.getMaxHP())):TQ.setCSS(c.wallBar,"display","none")},v=function(){if(!z()){TQ.setCSS(c.defBar,"display","none");return}TQ.setCSS(c.defBar,"display","block");var a={150301:"XIANJING",150302:"GUNMU",150303:"JUMA",150304:"LEISHI",150305:"NUJIAN"};for(var b in a)TQ.setTextEx(c["def_"+a[b]],0);var d=A();for(var e=0;e<d.length;++e){var f=d[e];TQ.setTextEx(c["def_"+a[f.getResId()]],f.getHP())}},w=function(b,e,f){for(var g=0;g<e.length;++g){var h=e[g],i=Actor.snew(a);i.setParent(c.map),i.setId(h.id),i.setType(h.type),i.setName(h.name),i.setCampName(b),i.setIcon(h.detail.icon),i.setResId(x(h)),i.setDirection(f),i.setPosition(d.getAbsPosition(h.pos)),i.setAction("stand"),i.setHP(h.detail.attrs[ATTR.HP],h.detail.attrs[ATTR.HP]),i.setUnitHP(h.detail.attrs[ATTR.UHP]),i.setObserver(D),a.getActorMgr().add(i),i.getResId()==150201&&a.getActorMgr().setMainWallId(i.getId())}},x=function(a){var b=0;if(a.type==ACTOR_TYPE.SOLDIER)b=a.resid;else if(a.type==ACTOR_TYPE.HERO){var c=Math.floor(a.detail.icon/100);b=150100+c}else a.type==ACTOR_TYPE.WALL&&a.pos.y==1?b=150201:a.type==ACTOR_TYPE.DEF&&(b=150300+a.resid);return b},y=function(){var b=null;return C("defender",function(c){c.getType()==ACTOR_TYPE.WALL&&c.getId()==a.getActorMgr().getMainWallId()&&(b=c)}),b},z=function(){return y()!=null},A=function(){var a=[];return C("defender",function(b){b.getType()==ACTOR_TYPE.DEF&&a.push(b)}),a},B=function(a){var b=[];return C(a,function(a){b.push(a)}),b},C=function(b,c){for(var d=0;d<a.getActorMgr().getCount();++d){var e=a.getActorMgr().getByIdx(d);e.getCampName()==b&&c(e)}},D=function(a,b,c){q("attacker"),q("defender"),t("attacker"),t("defender"),u(),v()}}),ShowSingleHeroFight=Class.extern(function(){this.calcFightCap=function(a){return a[0].detail.attrs[ATTR.SFC]}}),ShowSoldiersFight=Class.extern(function(){this.calcFightCap=function(a){var b=0;for(var c=0;c<a.length;++c){if(a[c].type!=ACTOR_TYPE.SOLDIER)continue;b+=a[c].detail.attrs[ATTR.FC]}return b}}),ShowRounds=Class.extern(function(){var a=null,b=null,c=[],d={x:0,y:0},e=1;this.init=function(c){b=this,a=c},this.setMapPosInfo=function(a,b){d=a,e=b},this.getAbsPosition=function(a){return{x:d.x+a.x*e,y:d.y+a.y*e}},this.setRounds=function(a){c=ConvertFightRounds.snew().splitRounds(a)},this.update=function(){a.getActorMgr().update();if(f())return;g()?i():(k(j()),r(j()))},this.isEnd=function(){return f()},this.skip=function(){c=[],a.getActorMgr().clear()};var f=function(){return c.length>0?!1:h()},g=function(){if(c.length==0)return f();var a=c[0];return a.length>0?!1:h()},h=function(){var b=a.getActorMgr().getCount();for(var c=0;c<b;++c){var d=a.getActorMgr().getByIdx(c);if(!d.isIdle())return!1}return!0},i=function(){c.splice(0,1)},j=function(){return c[0]},k=function(a){for(var b=0;b<a.length;++b){var c=a[b];c.event=="effect"?c.isDelete=l(c):c.event=="addeff"?c.isDelete=m(c):c.event=="removeeff"?c.isDelete=n(c):(o(c),c.isDelete=p(c))}},l=function(b){var c=a.getActorMgr().getById(b.targetid);return c?c.isIdle()?(EffectManager.addMapEffect(c.isHero(),b),!0):!1:!0},m=function(b){var c=a.getActorMgr().getById(b.id);if(!c)return!0;if(!c.isIdle())return!1;var d=EffectManager.createEffects(c,b);for(var e in d)c.getEffectContainer().add(d[e]);return!0},n=function(b){var c=a.getActorMgr().getById(b.id);return c?c.isIdle()?(c.getEffectContainer().remove(b.effuid),!0):!1:!0},o=function(b){var c=s(b);if(!c)return;if(c=="attackstate"){var d=a.getActorMgr().getById(b.targetid);if(!d)return;if(d.getType()!=ACTOR_TYPE.WALL)return;for(var e=0;b.effects&&e<b.effects.length;++e){var f=b.effects[e];if(!f.targetid||f.targetid!=b.targetid)continue;f.targetid=a.getActorMgr().getMainWallId()}b.targetid=a.getActorMgr().getMainWallId()}else if(c=="diestate"){var g=a.getActorMgr().getById(b.id);if(!g)return;if(g.getType()!=ACTOR_TYPE.WALL)return;b.id=a.getActorMgr().getMainWallId()}},p=function(b){var c=s(b);if(!c)return!0;var d=b.id?b.id:b.userid,e=a.getActorMgr().getById(d);if(!e)return!0;if(!e.isIdle())return!1;if(q(b.seq,b.subseq))return!1;var f=a.getActorMgr().getById(b.targetid);if(f&&!f.isIdle())return!1;if(c=="attackstate"&&!f)return!0;var g=t(b),h=StateFactory.createByType(e,f,c,g);return e.setState(h),!0},q=function(a,b){var c=j();for(var d=0;c&&d<c.length;++d){var e=c[d];if(e.seq==a&&e.subseq<b)return!0}return!1},r=function(a){for(var b=a.length-1;b>=0;--b)a[b].isDelete&&a.splice(b,1)},s=function(a){return a.event=="move"?"movestate":a.event=="attack"||a.event=="miss"||a.event=="berserk"?"attackstate":a.event=="die"?"diestate":null},t=function(a){if(a.event!="move")return a;var c={};TQ.dictCopy(c,a),c.paths=[];for(var d=0;d<a.paths.length;++d)c.paths.push(b.getAbsPosition(a.paths[d]));return c}}),ShowFightResult=Class.extern(function(){var a=1e4,b=10001,c=1e5,d=null,e=null,f=null,g=null,h=null,i=null,j=null,k=null;this.init=function(a,b,c){f=this,d=a,e=b,g=c},this.initFight=function(a,b,c){h&&(h.stop(),h=null),i=a,j=b,k=c},this.update=function(){l(),this._isWorldBossType()?this._worldBossResultCheck():this._commResultCheck()},this._isWorldBossType=function(){return k?k.type=="worldboss":!1},this._worldBossResultCheck=function(){if(h.isEnd()&&!UIM.getDlg("worldbossresult").isShow()){var a=UIM.getDlg("worldbossresult");a.openDlg({hurt:k.hurt}),a.setHideCaller({self:f,caller:p})}},this._commResultCheck=function(){h.isEnd()&&!n()&&o()};var l=function(){if(!h){var e=d.getImgr().getFightDemoRounds(i,j),f=FightResultMaker.snew(d).isMySucc(e),k=f?a:b;h=d.getAnimMgr().alloc(g.map,k),h.setZIndex(c),h.setPosition(m()),h.play()}},m=function(){var a=d.getWinSizer().getValidClientSize(),b=h.getSize();return{x:(a.cx-b.cx)/2,y:(a.cy-b.cy)/2}},n=function(){return UIM.getDlg("fightresult").isShow()},o=function(){var a=UIM.getDlg("fightresult");a.openDlg(i,j),a.setHideCaller({self:f,caller:p})},p=function(){e.hide()}}),WorldBossResultDlg=JBaseDlg.ex({setHideCaller:function(a){this.hideCaller_=a},_getDlgCfg:function(){return{modal:!0,title:rstr.military.worldbossresult.title,pos:{x:"center",y:100},uicfg:uicfg.military.worldbossresult}},_setCallers:function(){this.dlg_.setCaller({self:this,caller:this._onDlgEvent})},_initInfo:function(){TQ.setTextEx(this.items_.desc,TQ.format(rstr.military.worldbossresult.result,RStrUtil.formatResNumStr(this.params_.hurt)))},_onDlgEvent:function(a){a==C_SYS_DLG_HIDE&&this.hideCaller_&&this.hideCaller_.caller.call(this.hideCaller_.self)}})