var e=0,t=null,n=8,i=0,l=4,a=[],r=[[]],o=1e3,s=0,c=!0,u=0;const d=2;function m(e){e.style.outline="1px solid orange"}function h(e){e.style.outline="1px solid green"}function f(e,t){return document.getElementById("lap_table_"+e).rows[t+1]}function v(e,t,n){return f(e,t).cells[n+d]}function p(e,t,n){return parseFloat(1*v(e,t,n).innerText)}function g(e,t){var n=f(e,t);return n.cells[n.cells.length-4]}function _(e,t){return parseFloat(1*g(e,t).innerText)}function b(e,t){var n=f(e,t);return n.cells[n.cells.length-2]}function x(e,t){var n=f(e,t);return n.cells[n.cells.length-1]}function I(e,t,n){var i=f(e,t);i.cells[i.cells.length-3].innerText=n}function y(e,t,a,r){if(!(a>=l)){var o=function(e,t){return parseFloat(x(e,t).innerText)}(e,t),s=0;if(r/=1e3,0!=i||0!=a){if(o=Math.min(o,r),0==p(e,t,a))!function(e,t,n){var i=new SpeechSynthesisUtterance;const l=document.getElementById("voices");i.lang="en",i.text=`${e} lap ${t} is ${n} seconds`,console.log(i.voice),i.voice=speechSynthesis.getVoices().filter((function(e){return e.name===l.value}))[0],speechSynthesis.speak(i)}(function(e,t){return f(e,t).cells[1].lastChild.value}(e,t),a+i,r.toFixed(2)),function(e,t,n){g(e,t).innerText=n}(e,t,(_(e,t)+r).toFixed(3)),function(e){for(var t=[],i=0;i<n;++i){var l=_(e,i);l>0&&(t[t.length]={num:i,time:l})}for(t.sort((function(e,t){return e.time-t.time})),i=0;i<t.length;++i){I(e,t[i].num,i+1)}}(e);if(o.toFixed(3)==r.toFixed(3)){for(var c=v(e,t,a),u=0;u<l;++u)v(e,t,u).classList.remove("best_lap");c.classList.add("best_lap")}}!function(e,t,n,i){f(e,t).cells[n+d].innerText=i}(e,t,a,r);s=0;for(u=0==i;u<l;++u){var m=p(e,t,u);if(0==m||isNaN(m))break;s+=m}(function(e,t,n){b(e,t).innerText=n})(e,t,(s/=u-(0==i)).toFixed(3)),function(e,t,n){x(e,t).innerText=n}(e,t,o.toFixed(3))}}function E(t){var n="E"==t[0];n&&(t=t.substr(1));var i=parseInt(t[1]),l=t[2];if(n)switch(l){case"R":e=parseInt(t.substr(3),16);break;case"y":var o=parseInt(t.substr(3,8),16),c=parseInt(t.substr(11,4),16);null==r[i]&&(r[i]=[]),r[i].push({time:o,rssi:c}),s=Math.max(s,o)}else switch(l){case"L":var u=parseInt(t.substr(3,2),16),d=parseInt(t.substr(5),16);y(e,i,u,d);break;case"A":a[i]="1"==t[3];var m=f(e,i).cells[0].lastChild;h(m),m.checked=a[i];break;case"R":document.getElementById("race_mode").innerHTML=parseInt(t[3])?"Racing":"Finished"}}function C(e){for(var t=e.data.split("\n"),n=0;n<t.length;++n)E(t[n])}function k(e,t){var i=[];null==e&&(e=0);for(var l=0;l<n;++l)if(a[l]&&null!=r[l]){var o=i.length;i[o]={name:"Pilot"+l,data:[]};for(var s=r[l].length-1;s>=0;--s){var c=r[l][s].rssi,u=r[l][s].time;if(null==t&&(t=u),u<e)break;u>t||i[o].data.push({x:u,y:c})}i[o].data.reverse()}return i}!function e(n){(t=new WebSocket(n)).onmessage=C,t.onclose=function(){setTimeout((function(){e(n)}),1e3)},t.onopen=function(){t.send("ER*a\n"),t.send("R*a\n")}}("ws://192.168.4.1/ws"),document.getElementById("start_race_button").onclick=function(){e+=1,l=parseInt(document.getElementById("max_laps").value),function(e,l){if(console.log("Building table with race_num "+e),null==(r=document.getElementById("lap_table_"+e))){var r,o;for((r=document.getElementById("lap_table_default").cloneNode(!0)).id="lap_table_"+e,o=l;0!=o;o--){(s=r.rows[0].insertCell(d)).outerHTML='<th align="center">Lap '+(o-(0==i))+"</th>"}for(o=0;o<n;o++){var s,c=r.insertRow(-1);(s=c.insertCell(-1)).innerHTML='<input id="pilot_active_box_'+o+'" value='+o+' type="checkbox"></input>',s.firstChild.onclick=function(){m(this),a[parseInt(this.value)]=void 0,t.send(`R${this.value}A${this.checked?1:0}\n`)},s.firstChild.checked=a[o],h(s.firstChild),null==a[o]&&m(s.firstChild),s=c.insertCell(-1);var u=localStorage.getItem("pilot_name_"+o);null==u&&(u="Pilot "+(o+1)),s.innerHTML='<input id="pilot_name_'+o+'" type="text" name="pilot" value="'+u+'" oninput=update_default_pilot_name('+o+")>";for(var f=0;f<l;++f)c.insertCell(-1);c.insertCell(-1),c.insertCell(-1),c.insertCell(-1),c.insertCell(-1).innerText="99999"}var v=document.getElementById("table_container"),p=document.createElement("div");p.setAttribute("class","tabcontent"),p.id="round_tab_content_"+e,v.appendChild(p),p.appendChild(r);var g=document.getElementById("round_buttons");console.log(g),g.innerHTML+="<button class='tablinks' onclick='openRound(event,"+e+")'>Round "+e+"</button>\n",g.children[g.childElementCount-1].click()}}(e,l),t.send("R*R1\n")},document.getElementById("stop_race_button").onclick=function(){t.send("R*R0\n")},function e(){const t=document.getElementById("voices");var n=speechSynthesis.getVoices();if(0!=n.length){n.forEach(e=>{const n=document.createElement("option");n.value=e.name,n.innerHTML=e.name,n.id=e.name,t.appendChild(n),e.name.includes("english")&&(t.value=e.name)});var i=localStorage.getItem("voice");null!=i&&(t.value=i),t.addEventListener("change",e=>{localStorage.setItem("voice",t.value)})}else setTimeout(()=>{e()})}(),document.getElementById("max_laps").value=l;var T={low:0,high:1e3,showPoint:!1,lineSmooth:!1,axisX:{type:Chartist.AutoScaleAxis,onlyInteger:!0,labelInterpolationFnc:function(e,t){return t%13==0?e/1e3:null}}},M=0,w=new Chartist.Line(".ct-chart",{},T);const B=document.getElementById("graph_div");function L(e,t,n){return e<=t?t:e>=n?n:e}B.addEventListener("wheel",(function(e){return o+=100*e.deltaY,o=Math.max(o,100),e.preventDefault(),!1}),!1),B.addEventListener("mousemove",(function(e){if(1==e.buttons){c=!1;var t=Math.min(Math.max(u-e.movementX*(o/1e3),0),s);t-o>0&&(u=t)}}),!1);M=1;setInterval((function(){c?(start=Math.max(0,s-o),end=void 0,u=s):(end=u,start=Math.max(0,end-o)),w.update({series:k(start,end)})}),100),r[0]=[{time:0,rssi:5}],r[1]=[{time:0,rssi:8}],a[0]=!0,a[1]=!0,setInterval((function(){var e=L(r[0][r[0].length-1].rssi+(100*Math.random()-50),0,1e3),t=L(r[1][r[1].length-1].rssi+(100*Math.random()-50),0,1e3);r[0].push({time:M,rssi:e}),r[1].push({time:M,rssi:t}),s=M+=50}),50);