<?php
if (!isset($argv[1]))
{
	echo "[usage] - genClass <ClassName>\n";
	return ;
}

$name = $argv[1];

system("touch ".$name.".cpp ".$name.".hpp");

$hpp = "\n#ifndef ".strtoupper($name)."_HPP\n# define ".strtoupper($name)."_HPP\n\n# include <iostream>\n\nclass ".$name."\n{\n 	public:\n		".$name."(void);\n		".$name."(".$name." const & src);\n		".$name."& operator=(".$name." const & rhs);\n		"."~".$name."(void);\n"."};\n\n#endif\n";
$cpp= "\n#include \"".$name.".hpp\"\n\n".$name."::".$name."(void)\n{\n	return ;\n}\n\n".$name."::".$name."(".$name." const & src)"."\n{\n	*this = src;\n	return ;\n}\n\n".$name."& ".$name."::"."operator=(".$name." const & rhs)"."\n{\n	static_cast<void>(rhs);\n	return (*this);\n}\n\n".$name."::~".$name."(void)\n{\n	return ;\n}\n";

file_put_contents($name.".hpp", $hpp);
file_put_contents($name.".cpp", $cpp);

echo "Done !\n";
?>