<?xml version="1.0" encoding="ISO-8859-1"?>
<ncl id="test_descriptor_focusSrc_2" xmlns="http://www.ncl.org.br/NCL3.0/EDTVProfile">
	<head>
		<regionBase>
			<region id="reg" />
		</regionBase>
		<descriptorBase>
			<descriptor id="desc" 
				region="reg" 
				focusIndex="1" 
				focusSrc="../../../../images/NoExiste.jpg"
				focusBorderWidth="2"/>
		</descriptorBase>
	</head>
	<body>
		<port id="port" component="image" />
		<media id="image" src="../../../../images/blue.jpg" descriptor="desc" >
			<property name="bounds" value="25%,25%,50%,50%" />
		</media>
	</body>
</ncl>
