#!/usr/bin/perl

open F,"<gl.h" and @gl=grep {/WINGDIAPI/}<F> and close F or die "i am dead";
my $API_METHOD_NAME="int API_EXPORTEDNAME(lua_State*L)";
#glXXX(a,b,c,d)

open API,">lgl.h" or die "cannot open lgl.h";
open CPP,">lgl.cpp" or die "cannot open lgl.cpp";
open EXPORTCPP,">exportAPI.cpp" or die "cannot open exportAPI.cpp";
print API "\#pragma once\nextern	\"C\"\n{\n#include \"lua.h\"\n#include \"lualib.h\"\n#include \"lauxlib.h\"\n}\nint ExportAPI(lua_State*L);\n";
print CPP "#include <windows.h>\n#include <gl/GL.h>\n#include <gl/GLU.h>\n#include\"lgl.h\"\n";
print EXPORTCPP "#include <windows.h>\n#include <gl/GL.h>\n#include <gl/GLU.h>\n#include\"lgl.h\"\n";
print EXPORTCPP "int ExportAPI(lua_State*L)\n{\n";

sub APIWithPointer
{
	
}

sub APINormal
{
	$ret=shift;
	$api_name=shift;
	$api_name=~s/\s//ge;
	$args=shift;
	print $ret." ".$api_name." ".$args."\n";
	my $temp=$API_METHOD_NAME;
	$temp=~s/EXPORTEDNAME/$api_name/ge;
	my @arg_array=split /,/,$args;
	print API $temp.";\n";
	print EXPORTCPP "\tlua_register(L,\"".$api_name."\",API_".$api_name.");\n";
	print CPP $temp."\n{\n";
	my $count=@arg_array;
	if($args=~/GLbitfield/)
	{
		print CPP "\tint argC = lua_gettop(L);\n\tunsigned int temp=0;\n\tfor (int i = 0; i < argC; ++i)\n\t{\n\t\ttemp |= lua_tointeger(L, i+1);\n\t}\n";	
	}
	print CPP "\t$api_name(";
	if(not $args=~/void/)
	{
		for($i=0;$i<$count;$i++)
		{
			$arg_array[$i]=~/(.+)\s+(.+)/;
			my $type=$1;
			$type=~s/\s//ge;
			my $argIndex=$i+1;
			
			print CPP "(".$type.")";
			if($type eq "GLenum" or $type eq "GLint" or $type eq "GLuint" or $type eq "GLsizei"
			 or $type eq "GLshort" or $type eq "GLushort" or $type eq "GLbyte" or $type eq "GLubyte")
			{
				print CPP "lua_tointeger(L,".($argIndex).")";
			}
			elsif($type eq "GLfloat" or $type eq "GLclampf" or $type eq "GLclampd" or $type eq "GLdouble")
			{
				print CPP "lua_tonumber(L,".($argIndex).")";
			}
			elsif($type eq "GLboolean")
			{
				print CPP "lua_toboolean(L,".($argIndex).")";
			}
			elsif($type eq "GLbitfield")
			{
				print CPP "temp";
			}
			if($i!=$count-1)
			{
				print CPP ",";
			}
		}
	}
	
	print CPP ");\n";
	print CPP "\treturn 0;\n}\n" if $ret=~/void/ or not print CPP "\treturn 1;\n}\n";
}

map 
{
	my $temp=$_;
	$temp=~/WINGDIAPI\s*(.+)\s*APIENTRY\s*(.+)\s*\((.+)\).+/;
	my $ret=$1;
	my $api_name=$2;
	my $args=$3;
	APINormal($ret,$api_name,$args) unless $args=~/\*/ and (APIWithPointer($ret,$api_name,$args) or true);
}@gl;

print EXPORTCPP "\treturn 0;\n}\n";
close API;
close CPP;
close ExportCPP;
<STDIN>;