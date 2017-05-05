#!/usr/bin/php
<?php

# COLORS
define("BLACK", "\033[1;30m");
define("RED", "\033[1;31m");
define("GREEN", "\033[1;32m");
define("YELLOW", "\033[1;33m");
define("BLUE", "\033[1;34m");
define("PURPLE", "\033[1;35m");
define("CYAN", "\033[1;36m");
define("GREY", "\033[1;37m");
define("LYELLOW", "\033[1;38m");
define("WHITE", "\033[1;39m");
define("STOP", "\033[0m");

# CLASS
class Polynome
{
	# VARIABLES
	private $equation;
	private $a;
	private $b;
	private $c;
	private $delta;
	private $x1;
	private $x2;
	private $degree;
	private $left;
	private $right;
	private $reduced;
	# verbose mode to have detailled operations
	private static $verbose = true;
	# dev mode to have moar detailled operations
	private static $dev = true;

	# CONSTRUCTOR
	public function __construct($str)
	{
		if (self::$dev) { echo GREEN."Constructor called...\n".STOP; }
		$this->setEquation($str);
		# set left and right
		$this->setEquation(str_replace("+", "|+", $this->getEquation()));
		if (self::$dev) { echo GREEN.$this->getEquation().STOP; }
		$this->setEquation(str_replace("-", "|-", $this->getEquation()));
		if (self::$dev) { echo GREEN.$this->getEquation().STOP; }
		$this->setLeft(explode("|", explode("=", $this->getEquation())[0]));
		if (self::$dev) { echo GREEN.$this->getEquation().STOP; }
		$this->setRight(explode("|", explode("=", $this->getEquation())[1]));
		if (self::$dev) { echo GREEN.$this->getEquation().STOP; }
		# trim left
		foreach($this->getLeft() as $value)
		{
			if (preg_match("/X\^([0-9]+)/", $value, $degree))
				$this->left[intval($degree[1])] = floatval($this->getCoef($value));
		}
		# trim right
		foreach($this->getRight() as $value)
		{
			if (preg_match("/X\^([0-9]+)/", $value, $degree))
				$this->right[intval($degree[1])] = floatval($this->getCoef($value));
		}
		if (self::$dev) { echo WHITE."degree[0] = ".$degree[0]."\ndegree[1] = ".$degree[1]."\n".STOP; }
	}

	# return coef well formatted
	public function getCoef($str)
	{
		# avoid the pattern "X" + "^" + "nbr"
		$result = preg_replace("/X\^([0-9]+)/", "", $str);
		# check result
		if (self::$dev) { echo WHITE."result = ".$result."\n".STOP; }
		# avoid the "*"
		$result = str_replace("*", "", $result);
		# check if the result is good
		if (!is_numeric($result))
		{ 
			echo RED."Error: Coef bad formatted -> ".$result."\n".STOP;
			exit();
		}
		if (self::$dev) { echo WHITE."getCoef() -> result = ".$result."\n".STOP; }
		return ($result);
	}
	
	# ACCESSORS
	public function getEquation() { return ($this->equation); }
	public function getA() { return ($this->a); }
	public function getB() { return ($this->b); }
	public function getC() { return ($this->c); }
	public function getDelta() { $this->setDelta(); return ($this->delta); }
	public function getX1() { return ($this->x1); }
	public function getX2() { return ($this->x2); }
	public function getDegree()
	{
		if (self::$dev)
			echo BLUE."getDegree() called...\n".STOP;
		$this->setDegree();
		echo CYAN."Polynomial degree: ".YELLOW.$this->degree."\n".STOP;
		return ($this->degree);
	}
	public function getLeft() { return ($this->left); }
	public function getRight() { return ($this->right); }
	public function getReduced() { return ($this->reduced); }
	public function getVerbose() { return (self::$verbose); }
	public function setEquation($str) { $this->equation = $str; }
	public function setA($nbr) { $this->a = $nbr; }
	public function setB($nbr) { $this->b = $nbr; }
	public function setC($nbr) { $this->c = $nbr; }
	public function setDelta()
	{
		if (self::$dev)
			echo BLUE."setDelta() called...\n".STOP;
		$this->delta = $this->getB() * $this->getB() - 4 * $this->getA() * $this->getC();
		if (self::$verbose)
			echo PURPLE."Δ = b^2 - 4ac = ".$this->delta."\n".STOP;
	}
	public function setX1($nbr) { $this->x1 = $nbr; }
	public function setX2($nbr) { $this->x2 = $nbr; }
	public function setDegree() { $this->degree = max(array_keys($this->reduced)); }
	public function setLeft($str) { $this->left = $str; }
	public function setRight($str) { $this->right = $str; }
	public function setReduced($str) { $this->reduced = $str; }

	# is $input an integer
	public function isInteger($input) { return (ctype_digit(strval($input))); }
	# is $input positive
	public function isPositive($input) { return ($input > 0 ? true : false); }

	# return the square root of $nbr
	public function sqRt($nbr)
	{
		if (self::$dev) { echo BLUE."sqRt() called...\n".STOP; }
		$result = $nbr;
		$i = 0;
		if ($nbr <= 0)
			return (0);
		while ($i < 8)
		{
			$result = ($result + ($nbr / $result)) / 2;
			$i++;
		}
		if (self::$dev) { echo WHITE."sqRt() -> result = ".$result."\n".STOP; }
		return ($result);
	}

	# write the reduced form of the polynome
	public function reducto()
	{
		if (self::$dev) { echo BLUE."reducto() called...\n".STOP; }
		$this->setReduced($this->getLeft());
		# transform the polynome in equation ... ish
		foreach($this->getRight() as $key => $value)
		{
			if (isset($this->reduced[$key]))
				$this->reduced[$key] -= $value;
			else
				$this->reduced[$key] = 0 - $value;
			if ($this->reduced[$key] == 0 && $key != 0)
				unset($this->reduced[$key]);
		}
		echo CYAN."Reduced form: ".YELLOW;
		# reformat the equation for printing
		foreach($this->getReduced() as $key => $value)
		{
			if ($value >= 0 && $key != 0)
			{
				if (preg_match("/[+]([0-9]+)[*]X/", $value))
					$value = str_replace("+", "", $value);
				echo "+ ";
			}
			if ($value < 0)
			{
				$value = -$value;
				echo "- ";
			}
			if (preg_match("/[*]X/", $value))
				$value = str_replace("*X", "", $value);
			echo $value." * X^".$key." ";
		}
		if (self::$dev) { echo WHITE."\ngetReduced() -> result = \n"; print_r($this->getReduced()); echo "\n".STOP; }
		echo YELLOW."= 0"."\n".STOP;
	}

	# call the function corresponding to the degree 
	public function solve()
	{
		if (self::$dev) { echo BLUE."solve() called...\n".STOP; }
		if ($this->degree == 0)
			$this->zeroDegree();
		else if ($this->degree == 1)
			$this->firstDegree();
		else if ($this->degree == 2)
			$this->secondDegree();
		else
			$this->toomuchDegree();
	}

	# 0 DEGREE
	public function zeroDegree()
	{
		if (self::$dev) { echo BLUE."zeroDegree() called...\n".STOP; }
		if ($this->reduced[0] == 0)
			echo CYAN."All real numbers are solutions.\n".STOP;
		else
			echo CYAN."This equation has no solutions.\n".STOP;
	}

	# 1st DEGREE
	# (ax + b = 0 -> ax = -b -> x = -b/a)
	# factor: ƒ(x) = a(x-x1)^2
	public function firstDegree()
	{
		if (self::$dev) { echo BLUE."firstDegree() called...\n".STOP; }
		$this->setA($this->reduced[1]);
		$this->setB($this->reduced[0]);
		$x = -$this->getB() / $this->getA();
		if (self::$verbose)
		{
			echo PURPLE."x = -b / a = -".$this->getB()." / ";
			$value = $this->getA();
			if (preg_match("/[+]([0-9]+)[*]X/", $value))
			{
				$value = str_replace("+", "", $value);
				$value = str_replace("*X", "", $value);
				echo $value." = ".$x.STOP;
			}
			else { echo $value." = ".$x.STOP; }
		}
		echo CYAN."\nThe solution is:"."\n".YELLOW.$x."\n".STOP;
		if ($this->isInteger($this->getB()) && $this->isInteger($this->getA()) && self::$verbose == true)
			echo PURPLE.-$this->getB()."/".$this->getA()."\n".STOP;
		# print factor
		if (self::$verbose)
		{
			echo PURPLE."ƒ(x) = ".$value."(x";
			if ($x > 0)
				echo "-".$x.")^2\n".STOP;
			else
				echo $x.")^2\n".STOP;
		}
	}

	# 2nd DEGREE
	# (ax^2 + bx + c -> Δ = b^2 - 4ac -> Δ = 0 _ x1 = -b / 2a -> Δ > 0 _ x1 = -b + √Δ / 2a _ x2 = -b - √Δ / 2a)
	# factor: ƒ(x) = a(x-x1)^2
	# factor: ƒ(x) = a(x-x1)(x-x2)
	public function secondDegree()
	{
		if (self::$dev) { echo BLUE."secondDegree() called...\n".STOP; }
		$this->setA($this->reduced[2]);
		$this->setB($this->reduced[1]);
		$this->setC($this->reduced[0]);
		$delta = $this->getDelta();
		if ($delta > 0)
		{
			$sqrt = $this->sqRt($delta);
			$this->setX1((-$this->getB() + $sqrt) / ($this->getA() * 2));
			if (self::$verbose)
			{
				echo PURPLE."x1 = -b + √Δ / 2a = ";
				if ($this->getB() > 0)
					echo "-".$this->getB()." + ".$sqrt." / 2".$this->getA()." = ".$this->getX1()."\n".STOP;
				else
					echo $this->getB()." + ".$sqrt." / 2".$this->getA()." = ".$this->getX1()."\n".STOP;
			}
			$this->setX2((-$this->getB() - $sqrt) / ($this->getA() * 2));
			if (self::$verbose)
			{
				echo PURPLE."x2 = -b - √Δ / 2a = ";
				if ($this->getB() > 0)
					echo "-".$this->getB()." - ".$sqrt." / 2".$this->getA()." = ".$this->getX2()."\n".STOP;
				else
					echo $this->getB()." - ".$sqrt." / 2".$this->getA()." = ".$this->getX2()."\n".STOP;
			}
			echo CYAN."Discriminant ".YELLOW.$delta.CYAN.", is strictly positive, the two solutions are:\n".YELLOW;
			echo $this->getX2()."\n".$this->getX1()."\n";
			echo STOP;
			if (self::$verbose)
			{
				echo PURPLE."ƒ(x) = ".$this->getA()."(x";
				if ($this->getX1() > 0 && $this->getX2() > 0)
					echo "-".$this->getX1().")(x-".$this->getX2().")\n".STOP;
				else if ($this->getX1() < 0 && $this->getX2() < 0)
					echo $this->getX1().")(x".$this->getX2().")\n".STOP;
				else if ($this->getX1() > 0 && $this->getX2() < 0)
					echo "-".$this->getX1().")(x".$this->getX2().")\n".STOP;
				else if ($this->getX1() < 0 && $this->getX2() > 0)
					echo $this->getX1().")(x-".$this->getX2().")\n".STOP;
			}
		}
		else if ($delta < 0)
		{
			$s = -$this->getB() / ($this->getA() * 2);
			if (self::$verbose)
			{
				echo PURPLE."x = -b / a * 2 = ";
				if ($this->getB() > 0)
					echo "-".$this->getB()." / ".$this->getA()." * 2 = ".$s."\n".STOP;
				else
					echo $this->getB()." / ".$this->getA()." * 2 = ".$s."\n".STOP;
			}
			echo CYAN."Discriminant ".YELLOW.$delta.CYAN.", is strictly negative, there are no solutions\n".STOP;
		}
		else
		{
			$this->setX1(-$this->getB() / 2 * $this->getA());
			if (self::$verbose)
			{
				echo PURPLE."x1 = -b / 2a = ";
				if ($this->getB() > 0)
					echo "-".$this->getB()." / 2 * ".$this->getA()." = ".$this->getX1()."\n".STOP;
				else
					echo $this->getB()." / 2 * ".$this->getA()." = ".$this->getX1()."\n".STOP;
			}
			echo CYAN."Discriminant is ".YELLOW."0".CYAN.", the solution is:\n".STOP;
			echo $this->getX1()."\n";
			if (self::$verbose)
			{
				echo PURPLE."ƒ(x) = ".$this->getA()."(x";
				if ($this->getX1() > 0)
					echo "-".$this->getX1().")^2\n".STOP;
				else
					echo $this->getX1().")^2\n".STOP;
			}
		}
		# get the side of the curve
		if (($this->getA() > 0) && ($this->getVerbose() == true))
			echo PURPLE."The curve is decreasing to his summit and increase after\n".STOP;
		if (($this->getA() < 0) && ($this->getVerbose() == true))
			echo PURPLE."The curve is increasing to his summit and decrease after\n".STOP;
	}

	# TooMuch DEGREE
	public function toomuchDegree()
	{
		if (self::$dev)
			echo BLUE."toomuchDegree() called...\n".STOP;
		echo CYAN."The polynomial degree is greater than 2, I can't solve\n".STOP;
	}

	# DESTRUCTOR
	public function __destruct() { if (self::$dev) { echo RED."Destructor called...\n".STOP; } }
}

# MAIN
if ($argc != 2)
	echo RED."Usage: ./computorv1.php \"equation\"\n".STOP;
if ($argc == 2)
{
	$equation = $argv[1];
	# trim equation
	$equation = str_replace(" ", "", $equation);
	# syntax + lexical error troubleshooting
	$equation = str_replace("+X", "+0*X", $equation);
	if (self::$correction) { echo $equation; }
	$equation = str_replace("-X", "-0*X", $equation);
	if (self::$correction) { echo $equation; }
	$equation = str_replace("=X", "=0*X", $equation);
	if (self::$correction) { echo $equation; }
	if (preg_match("/[^0-9X*+\-\^=.]+/", $equation) == 1)
	{
		echo RED."Error: Unauthorized characters.\n".STOP;
		return ;
	}
	if (strpos($equation, '=') === false)
	{
		echo RED."Error: Missing \"=\" symbol in the equation.\n".STOP;
		return ;
	}
	# do the magic !
	$poly = new Polynome($equation);
	$poly->reducto();
	$poly->getDegree();
	$poly->solve();
}
?>