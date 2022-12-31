<?php
// Please rename to index.php
$dir_scan=scandir("ovpn");
foreach ($dir_scan as $index => $key){
	if ($index > 1)
		echo "<a download href=\"ovpn/".$key."\">".$key."</a><br>";
}
?>
