ActTerraceDlg=BaseDlg.extern(function(){var a=null,b=0;this._init=function(){a=this,this.g_.regEvent(EVT.NET,NETCMD.ACT_TERRACE,this,this._onSvrPkg)},this._isCanOpen=function(){if(this.g_.getImgr().getRoleRes().level<res_enter_terrace_need_rolelevel){var a=TQ.format(rstr.activity.terrace.maindlg.tip.roleLevelNotArrived,res_enter_terrace_need_rolelevel);return this.g_.getGUI().msgBox(rstr.comm.msgts,a,MB_F_CLOSE,null),!1}return!0},this._getDlgCfg=function(){return{modal:!1,title:rstr.activity.terrace.maindlg.title,pos:{x:"center",y:40},uicfg:uicfg.activity.terrace.maindlg}},this._afterCreate=function(){if(TQ.isIE6())for(var a=0;a<9;++a)this.items_["gate"+(a+1)].resetUIBack(uiback.btn.forIE6Terracegatebtn)},this._setCallers=function(){for(var a=0;a<9;++a)this.items_["gate"+(a+1)].setCaller({self:this,caller:g});this.items_.buyBtn.setCaller({self:this,caller:h}),this.items_.enterBtn.setCaller({self:this,caller:i})},this._initInfo=function(){f(),ActTerraceSender.sendGetBaseInfo(this.g_),UIM.getDlg("actterraceexped").reset(),b==0&&this.items_.gate1.click()},this._onSvrPkg=function(a){c(a.data.results),d(a.data.baseInfo),e(a.data.enterTerrace)};var c=function(b){if(!b)return;TQ.dictCopy(a.g_.getImgr().getActTerrace().results,b)},d=function(b){if(!b)return;TQ.dictCopy(a.g_.getImgr().getActTerrace().baseInfo,b);if(!a.isShow())return;b=a.g_.getImgr().getActTerrace().baseInfo;for(var c=0;c<9;++c)a.items_["gate"+(c+1)].enable(c<b.maxGate.gateId);TQ.setTextEx(a.items_.todayFreeTimes,TQ.format(rstr.activity.terrace.maindlg.lbl.todayFreeTimes,b.today.freeTimes,b.today.maxTimes)),TQ.setTextEx(a.items_.todayItemTimes,TQ.format(rstr.activity.terrace.maindlg.lbl.todayItemTimes,b.today.itemTimes)),b.curGate.gateId||(b.curGate.gateId=0);var d=Math.clamp(b.curGate.gateId,1,9);a.items_["gate"+d].click()},e=function(b){if(!b)return;a.hideDlg()},f=function(){TQ.setTextEx(a.items_.todayFreeTimes,TQ.format(rstr.activity.terrace.maindlg.lbl.todayFreeTimes,0)),TQ.setTextEx(a.items_.todayItemTimes,TQ.format(rstr.activity.terrace.maindlg.lbl.todayItemTimes,0))},g=function(b){j(b);var c=res_terrace[b];TQ.setTextEx(a.items_.gateName,c[0].gateName),a.items_.heroList.setItemCount(c.length);for(var d=0;d<a.items_.heroList.getCount();++d){var e=a.items_.heroList.getItem(d),f=c[d],g=ItemResUtil.findItemres(f.heros[0]);TQ.setTextEx(e.exsubs.no,d+1),TQ.setTextEx(e.exsubs.name,f.heroName),TQ.setTextEx(e.exsubs.sfightcap,g.singlefightcap)}},h=function(){UIM.getDlg("buyitem").openDlg({id:0,resid:FIXID.HEIMULING,number:1e5})},i=function(){var c=a.g_.getImgr(),d=c.getActTerrace().baseInfo;if(d.today.freeTimes==d.today.maxTimes&&d.today.itemTimes==0&&c.getItemNumByResId(FIXID.HEIMULING)>0){a.g_.getGUI().msgBox(rstr.comm.msgts,rstr.activity.terrace.maindlg.lbl.confirmUseItem,MB_F_YESNO,{self:a,caller:function(c){c==MB_IDYES&&ActTerraceSender.sendEnterTerrace(a.g_,b)}});return}ActTerraceSender.sendEnterTerrace(a.g_,b)},j=function(c){b=c;for(var d=0;d<9;++d){var e=a.items_["gate"+(d+1)];e.setPress(e.getId()==b)}}})