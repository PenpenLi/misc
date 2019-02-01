document.domain = "qq.com";
var iwan_gw = {
	gameId : 28,
	gameCode : "jh",
	appId : 0,
	btnSelectId : "btnReSelect",
	CHAreaId : [],
	iwan : "http://iwan.qq.com",
	indexURL : function() {
		return this.iwan + "/" + this.gameCode + ".htm";
	},
	serverURL : function() {
		return this.iwan + "/" + this.gameCode + "/server.htm"
	},
	cdkeyURL : function() {
		return this.iwan + "/" + this.gameCode + "/cdkey.htm"
	},
	loadQueue : function(urls, callback) {
		var i = 0;
		var loadScript = function() {
			if (i < urls.length) {
				$.getScript(urls[i], function() {
							i++;
							loadScript();
						});
			} else {
				if (callback) {
					callback();
				}
			}
		};
		loadScript();

	},
	// ���ؽӿ�����
	loadData : function(callback) {

		var urls = ['http://openwebgame.qq.com/app/RecentServerInfo.php?appid='
				+ this.appId];
		this.loadQueue(urls, callback);

	},
	/**
	 * �Ƿ�ΪƵ������
	 * 
	 * @param {}
	 *            areaId
	 * @return {Boolean}
	 */
	isCHArea : function() {

		var flag = false;

		return flag;
	},
	/**
	 * �Ƿ�ΪƵ��������
	 * 
	 * @param {serverId}
	 * 
	 * @return {Boolean}
	 */
	isCHServerPos : function(areaIndex, serverIndex) {
		return user_all_servers[areaIndex]['subcat'][serverIndex]['sAttrValue']['type'] == "1"
				? true
				: false;
	},
	isCHServer : function(serverId) {
		var pos = this.findServerPos(serverId);

		return this.isCHServerPos(pos[0], pos[1]);
	},
	// �ж������¼�ķ������Ƿ�Ϊ����
	isCHServerLast : function() {
		var flag = false;
		var serverId = "";
		if ($.isArray(user_recent_servers)) {
			if (user_recent_servers.length > 0) {
				serverId = user_recent_servers[user_recent_servers.length - 1];
				if (this.isCHServer(serverId)) {
					flag = true;
				} else {
					flag = false;
				}
			} else {
				flag = true;
			}

		} else {
			flag = true;
		}
		return flag;
	},

	getRecommHTML : function(isOne) {
		
		var btnHtml = "";
		var qqRcmd = [];
		$(user_all_servers).each(function(areaIndex, area) {
			$(area['subcat']).each(function(serverIndex, server) {
						if (server['sAttrValue']['iIsRecommend'] == "1") {
							qqRcmd.push(iwan_gw.getBtnHtml(areaIndex,
									serverIndex));
						}
					});
		});
		if (isOne) {

			btnHtml = qqRcmd[0];
		} else {
			btnHtml = qqRcmd.join("");
		}

		return btnHtml;
	},
	// �����Ƽ�������
	createRecommServer : function() {
		// �Ƽ��·�

		$("#recommend").html(this
				.getNewRecommHtml(this.isCHServerLast(), false).replace(
						/btn-server/g, 'btn-server btn-server-light'));

	},
	// ���������¼�ķ�����
	getLastHtml : function(isOne) {
		
		var pos = "";
		var btnHtml = "";
		var qqRcmd = [], my = [];
		var tempHtml = "";
		if ($.isArray(user_recent_servers)) {

			for (var i = user_recent_servers.length - 1; i >= 0; i--) {

				pos = iwan_gw.findServerPos(user_recent_servers[i]);
				if (pos.length != 0) {
					tempHtml = iwan_gw.getBtnHtml(pos[0], pos[1]);
					if (i == (user_recent_servers.length - 1)) {
						qqRcmd.push(tempHtml.replace(/btn-server/g,
								'btn-server btn-server-light'));
						my.push(tempHtml.replace(/btn-server/g,
								'btn-server btn-server-light'));
					} else {
						my.push(tempHtml);
					}
				}
			}
		}
		if (isOne) {
			btnHtml = qqRcmd[0];
		} else {
			btnHtml = "<div class='btnset clearfix' id='tabLast'><a href='#' class='here'>�����¼</a> <a href='#'>�ҵķ�����</a></div><div class='boxes clearfix' id='boxLast'><div>"
					+ qqRcmd.join("")
					+ "</div><div style='display:none;'>"
					+ my.join("") + "</div></div>";
		}

		return btnHtml;
	},
	// ������ҳ��ʼ��ť
	createServerStart : function() {

		// δ��¼

		$("#btnStart").html(this.getNewRecommHtml(true, true).replace(
				/btn-server/, "btn-server btn-start btn-start-server"));

		// ��¼
		if ($app.auth.isLogin()) {
			var btnHtml = this.getLastHtml(true);
			if (btnHtml != "") {
				$("#btnStart").html(btnHtml.replace(/btn-server/,
						"btn-server btn-start btn-start-server")).find("a")
						.append("<strong>[�����¼]</strong>");
			}
		}
	},
	createLastServer : function() {
		// ��½������ʾ
		if (top.$app.auth.isLogin()) {
			$("#last").html(this.getLastHtml(false));
			iwan.ui.tab({
						btnId : "tabLast",
						boxId : "boxLast",
						event : "click"
					});
		}
	},
	// ����ȫ���������б�
	createServerList : function() {
		var tabHtml = "";
		var boxHtml = "";
		var gcHtml = "";

		var isShow = false;
		var chCount = 0;
		var newChAreaIndex = 0;

		if (this.isCHServerLast()) {// ���˷�������ֻ��������
			$(user_all_servers).each(function(i, area) {
						if (area['sAttrValue']['type'] == "1") {
							chCount++;
							newChAreaIndex = i;
						}
					});

			$(user_all_servers).each(function(i, area) {
						if (area['sAttrValue']['type'] == "1") {
							if (newChAreaIndex == i) {
								isShow = true;
							} else {
								isShow = false;
							}
							tabHtml += iwan_gw.getTabHtml(i, area['sName'],
									isShow);
							boxHtml += iwan_gw
									.getServerBoxHtml(i, area, isShow);
						}
					});
		} else {// �����ˣ���������

			$(user_all_servers).each(function(i, area) {
						if (0 == i) {
							isShow = true;
						} else {
							isShow = false;
						}
						tabHtml += iwan_gw.getTabHtml(i, area['sName'], isShow);
						boxHtml += iwan_gw.getServerBoxHtml(i, area, isShow);

					});
		}

		// $("#tabServer").html(tabHtml);
		// $("#boxServer").html(boxHtml);

		$("#serverList").html("<div id='tabServer' class='btnset'>" + tabHtml
				+ "</div><div class='boxes' id='boxServer'>" + boxHtml
				+ "</div>");

		iwan.ui.tab({
					btnId : "tabServer",
					boxId : "boxServer",
					hereIndex : newChAreaIndex,
					event : "click"
				});

		$("#tabServer").find("a").click(function() {
					if (top.iwan) {
						setTimeout(function() {
									top.iwan.ui.resizeGameFrame($(document)
											.height());
								}, 100);
					}
				});

		$("a[name^='btnServer_']").click(function() {
					var t = this;
					if (!$app.auth.isLogin()) {
						top.$app.auth.login({
									callback : function() {
										top.location.href = $(t).attr("href");
									}
								});
						return false;
					}
					if ($(this).find("em").hasClass("s-care")) {
						alert("�ܱ�Ǹ��ͣ��ά���У����Ժ�ˢ��ҳ������");
						return false;
					}

				});

		if (top.iwan) {
			top.iwan.ui.resizeGameFrame($("body").height());
		}

	},
	/**
	 * ��ȡѡ���ť html
	 * 
	 * @param {i}
	 * 
	 * @param {area}
	 * 
	 * @return {}
	 */
	getTabHtml : function(tabIndex, name, isHere) {
		return "<a id='tab_" + tabIndex + "' class='" + (isHere ? 'here' : '')
				+ "' href='javascript:;'>" + name + "</a>";
	},
	/**
	 * ��ȡȫ���б��е���ѡ�html
	 * 
	 * @param {i}
	 * 
	 * @param {area}
	 * 
	 * @return {html}
	 */
	getServerBoxHtml : function(tabIndex, area, isShow) {
		var boxHtml = "";
		var btnHtml = "";
		var areaIndex = tabIndex;
		boxHtml += "<div id='box_" + tabIndex
				+ "' class='server-list clearfix'"
				+ (isShow ? "" : " style='display:none;'") + " >";
		// ������html
		var len = area['subcat'].length;

		$(area['subcat']).each(function(serverIndex, server) {

					btnHtml += iwan_gw.getBtnHtml(areaIndex, serverIndex);
				});

		boxHtml += btnHtml;
		boxHtml += "</div>";
		return boxHtml;
	},
	/**
	 * ��ȡ��ʼ��ϷURL
	 * 
	 * @param {gid}
	 * 
	 * @param {sid}
	 * 
	 * @param {sname}
	 * 
	 * @return url@string
	 */
	getStartURL : function(gid, sid, sname) {
		return 'http://iwan.qq.com/playgame?gid=' + gid + '&sid=' + sid
				+ '&sname=' + sname;
	},
	/**
	 * ����serverId ����λ��
	 * 
	 * @param {}
	 *            serverId
	 * @return {}
	 */
	findServerPos : function(serverId) {
		var res = [];
		var flag = true
		$(user_all_servers).each(function(i, area) {
					$(area['subcat']).each(function(j, server) {
								if (server['iNodeId'] == serverId) {
									res[0] = i;
									res[1] = j;
									flag = false;
									return false;
								}
							});
					if (!flag) {
						return false;
					}
				});
		return res;
	},
	/**
	 * ���ɷ�������ťhtml
	 * 
	 * @param {id}
	 * 
	 * @return {}
	 */
	getBtnHtml : function(areaIndex, subcatIndex) {
		
		
		var server = user_all_servers[areaIndex]['subcat'][subcatIndex];
		var html = "";
		html += '<a target="_blank" class="btn-server" name="btnServer_'
				+ server['iNodeId']
				+ '" href="'
				+ this.getStartURL(this.gameId, server['iNodeId'],
						server['sName']) + '" >';
		if (server['sAttrValue']['iIsRecommend'] == 1) {
			html += "<b></b>";
		}
		if (server['sAttrValue']['iIsNew'] == 1) {
			html += "<i></i>";
		}

		var status = 0;
		if (server['iStatus'] == 0) {
			status = 9;
		} else {
			if (server['sAttrValue']) {
				status = server['sAttrValue']['iBusyStatus'];
			} else {
				status = 9;
			}
		}

		var statusInfo = this.getStauts(parseInt(status, 10));

		html += '<em class="' + statusInfo[0] + '" title="' + statusInfo[1]
				+ '" ></em><span>' + server['sName'] + '</span></a>';
		
				return html;

	},
	/**
	 * ͨ������״̬�����Ӧ����ʽ��������ʾ
	 * 
	 * @param {status}
	 * @return array[style,tip]
	 */
	getStauts : function(status) {

		var style = "";
		var tip = "";

		switch (status) {
			case 9 :
				style = "s-care";
				tip = "ά��";
				break;
			case 0 :
				style = "s-free";
				tip = "��ͨ";
				break;
			case 1 :
				style = "s-crowd";
				tip = "ӵ��";
				break;
			case 2 :
				style = "s-full";
				tip = "��æ";
				break;
			default :
				style = "s-free";
				tip = "��ͨ";
				break;
		}

		return [style, tip];
	},
	/**
	 * �����ǳ�
	 * 
	 * @param {$nickBox}
	 * 
	 */
	setNick : function($nickBox) {
		$nickBox.html($app.auth.getQQNum());

		iwan.api.getNick(function(res) {
					$nickBox.html(res.nick);
				});

	},
	// ��ҳ��¼�����
	loginBox : function() {
		if ($app.auth.isLogin()) {
			$("#logout-box").show();
			$("#login-box").hide();
			this.setNick($("#logout-box").find("span"));
		}
		// ��¼
		$("#login-box>a").click(function() {
					top.$app.auth.login({
								callback : function() {
									top.location.href = iwan_gw.indexURL();

								}
							});
					return false;
				});
		// �˳�
		$("#logout-box>a").click(function() {
					if ($app.auth.isLogin()) {
						top.$app.auth.logout();
					}
					return false;
				});

	},
	// ��ȡ�Ƽ������˷����� isChLast�Ƿ�Ϊ���˷����� isOne �Ƿ�ֻȡһ��������
	getNewRecommHtml : function(isCHLast, isOne) {
		// �����������
		
		var tempArea = 0;
		var html = "";
		var x = 0;
		var y = 0;

		var arrHtml = [];
		var tempServer = [];

		if (isCHLast) {// ����
			
			$(user_all_servers).each(function(i, area) {
				if (area['sAttrValue']['type'] == "1") {
					$(area['subcat']).each(function(j, server) {
						
								if (server['sAttrValue']['iIsRecommend'] == "1") {
									arrHtml.push(iwan_gw.getBtnHtml(i, j));
								}
								tempServer = [i, j];
							});
				}
			});
			// �������Ƽ������� �����һ�����˷������Ƽ�
			if (arrHtml.length == 0) {
		
				arrHtml.push(iwan_gw.getBtnHtml(tempServer[0], tempServer[1]));
			}

		} else {// ������
			
			$(user_all_servers).each(function(i, area) {
				if (area['sAttrValue'] == ""
						|| area['sAttrValue']['type'] == "0") {

					$(area['subcat']).each(function(j, server) {
								if (server['sAttrValue']['iIsRecommend'] == "1") {

									arrHtml.push(iwan_gw.getBtnHtml(i, j));
								}
							});
				}
			});
		}

		if (arrHtml.length == 0) {
			return "";
		}

		if (isOne) {
			return arrHtml[arrHtml.length - 1];
		}

		return arrHtml.join("");

	},
	// ���ؿ�ʼ��Ϸ��ť�¼�
	startGameBox : function() {
		var $btnStart = $("#btnStart");
		var btnHtml = "";

		// δ��¼
		$btnStart.html(this.getNewRecommHtml(true, true).replace(/btn-server/,
				"btn-server btn-start"));
                

		// ��¼
		if ($app.auth.isLogin()) {
			btnHtml = this.getLastHtml(true);
			if (btnHtml != "") {
				$btnStart.html(btnHtml.replace(/btn-server/,
						"btn-server btn-start")).find("a")
						.append("<strong>[�����¼]</strong>");
			}
		}

		// ������Ϸ
		$btnStart.find("a").live("click", function() {
					if (!top.$app.auth.isLogin()) {

						top.$app.auth.login({
									callback : function() {
										top.location.href = iwan_gw.indexURL();
									}
								});
						return false;
					}
				});

		// �Ƽ��·�
		$("#btnCreate").html(this.getNewRecommHtml(true, true).replace(
				/btn-server/, "btn-server btn-create"));
		$("#btnCreate").click(function() {
					if (!top.$app.auth.isLogin()) {

						top.$app.auth.login({
									callback : function() {
										top.location.href = iwan_gw.indexURL();
									}
								});
						return false;
					}
					return false;
				});

	},
	// ��ѡ������
	selectServer : function() {
		$("#btnReSelect").click(function() {
					if (!top.$app.auth.isLogin()) {
						top.$app.auth.login({
									callback : function() {

										top.location.href = iwan_gw.serverURL();
									}
								});
						return false;
					}

				});
	},
	indexTab : function() {
		iwan.ui.tab({
					btnId : "tabs",
					boxId : "boxes",
					event : "mousemove"
				});
	},
	// ҳ�湦��
	indexFunc : function() {
		var t = this;
		//
		var tabId = "";
		$("[id^=tabBtns]").each(function() {
					tabId = $(this).attr("id").split("_")[1];
					iwan.ui.tab({
								btnId : "tabBtns_" + tabId,
								boxId : "tabBoxes_" + tabId,
								event : "mouseover"
							});
				});

		$("#picSlider").iwanSlider({
					effect : "slideLeftRight",
					event : "mouseenter",
					autoPlay : true
				});

		// ��ȡ���
		$("[id^=btnReceivePack]").click(function() {
					top.iwan.ui.receivePack({
								gameId : t.gameId,
								itemId : $(this).attr("id").split("_")[1]
							});
					return false;
				});

	},
	picList : function(options) {
		var o = {
			target : "",
			items : [{
						simg : "",
						img : ""
					}]
		};

		var o = $.extend({}, o, options)
		var html = "";
		$(o.items).each(function(i, val) {
			html += "<a class='pic-box" + (i + 1) + "' href='" + val['img']
					+ "'><img src='" + val['simg'] + "' /></a>";
		});

		$("#" + o.target).html(html);

		var $imgs = $("#" + o.target).find("a");

		var now = "";
		var pre = "";

		$imgs.mouseenter(function() {
					now = this;

					$(pre).animate({
								opacity : 0.5
							}, 200);

					$(now).animate({
								opacity : 1
							}, 200);

					pre = now;
				});

		$("#" + o.target).hover(function(e) {

					$imgs.each(function(i, v) {
								if (v != now) {
									$(v).animate({
												opacity : 0.5
											}, 200);
								}
							});

				}, function() {
					$imgs.animate({
								opacity : 1
							}, 200);
				});

	},

	serverEvent : function() {
		var t = this;
		$("#btnLogin").click(function() {
					if (!top.$app.auth.isLogin()) {
						top.$app.auth.login({
									callback : function() {
										t.showServer();
									}
								});
					}
					return false;
				});

		// �˳�
		$("#logout-box>a").click(function() {
					if ($app.auth.isLogin()) {
						top.$app.auth.logout({
									callback : function() {
										top.location.href = t.indexURL();
									}
								});
					}
					return false;
				});

		// ��ʾ����
		$("#btnMoreServer").click(function() {
					$("#boxServers").show();
					$("#boxStart").hide();

					if (top.iwan) {
						setTimeout(function() {
									top.iwan.ui.resizeGameFrame($(document)
											.height());
								}, 100);
					}
					return false;
				});

	},

	// ��ʾ������ҳ��ť&��¼����
	showServer : function() {
		var t = this;
		var $btnLogin = $("#btnLogin");
		var $btnStart = $("#btnStart");
		var $btnMoreServer = $("#btnMoreServer");

		if (top.$app.auth.isLogin()) {
			// ���ص�¼��ť
			$btnLogin.hide();

			// ��ʾ��ʼ��ť
			$btnStart.show();

			// ��ʾ�˳���ť
			$("#logout-box").show();
			this.setNick($("#logout-box").find("span"));

			// ��������
			t.loadData(function() {
						t.createServerStart();

						t.createRecommServer();

						t.createLastServer();

						t.createServerList();

						$btnMoreServer.show();

					});
		}
	},

	// ��ʼ��������ҳ���
	initServerPage : function() {
		var t = this;

		t.serverEvent();
		t.showServer();

	},
	// ��ʼ����ҳ���
	initIndexPage : function() {
		var t = this;
		t.loginBox();
		t.loadData(function() {
					t.startGameBox();
					t.selectServer();
					t.indexTab();
				});
		t.indexFunc();
	}
};

// ҳ��߶ȿ���
$(function() {

			if (top.iwan) {
				top.iwan.ui.resizeGameFrame($("body").height());
			}
		});/*  |xGv00|83a87d828363f43633707bafb611a7bf */