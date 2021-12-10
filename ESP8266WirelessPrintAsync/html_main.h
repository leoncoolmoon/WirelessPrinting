const  uint8_t index_html[]=R"=====(
<html>
<body>
<h1><!--#getDeviceName#--></h1>
<form enctype="multipart/form-data" action="/api/files/local" method="POST">
<p>You can also print from the command line using curl:</p>
<pre>curl -F "file=@/path/to/some.gcode" -F "print=true" <script type='text/javascript'> document.write(window.location.host) </script>/api/files/local</pre>
Choose a file to upload: <input name="file" type="file" accept=".gcode,.GCODE,.gco,.GCO"/><br/>
<input type="checkbox" name="print" id = "printImmediately" value="true" checked>
<label for = "printImmediately">Print Immediately</label><br/>
<input type="submit" value="Upload" />
</form>
<p><script>
function startFunction(command) {
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("POST", "/api/job");
  xmlhttp.setRequestHeader("Content-Type", "application/json");
  xmlhttp.send(JSON.stringify({command:command}));
}
</script>
<button onclick="startFunction('cancel')">Cancel active print</button>
<button onclick="startFunction('start')">Print <!--#uploadedName#--></button></p>
<p><a href="/download">Download <!--#uploadedName#--></a></p>
<p><a href="/info">Info</a></p>
<hr>
<p>WirelessPrinting <a href="https://github.com/probonopd/WirelessPrinting/commit/<!--#SKETCH_VERSION#-->"><!--#SKETCH_VERSION#--></a></p>
<!--#OTA#-->
</body></html>
)=====";

const  uint8_t E404_html[]=R"=====(
<h1>Page not found!</h1>
)=====";