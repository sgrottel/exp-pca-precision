for ($i = 16; $i -le 42; $i++) {
	$c = gc ("" + $i + ".txt") | out-string
	
	if ($c -match "(?ms)Double center naive:.*?max err: ([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Float center naive:.*?max err: ([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Double covar naive:.*?max err: ([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Float covar naive:.*?max err: ([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Double eigenvalues 2x2:.*?Overall error:\s*([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Float eigenvalues 2x2:.*?Overall error:\s*([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Double eigenvalues 3x3:.*?Overall error:\s*([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Float eigenvalues 3x3:.*?Overall error:\s*([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Double eigenvalues 4x4:.*?Overall error:\s*([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	if ($c -match "(?ms)Float eigenvalues 4x4:.*?Overall error:\s*([\d.]+)") {
		write-host $matches[1] ";" -NoNewline
	} else {
		write-host "0;" -NoNewline
	}
	
	
	write-host ""
}