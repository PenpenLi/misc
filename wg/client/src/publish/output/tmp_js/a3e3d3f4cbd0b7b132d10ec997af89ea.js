Caller=JClass.ex({_init:function(a,b){this._obj=a,this._caller=b},invoke:function(){this._caller.apply(this._obj,arguments)}}),NullCaller=JClass.ex({invoke:function(){}}).snew()