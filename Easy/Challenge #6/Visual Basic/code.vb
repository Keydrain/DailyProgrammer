'Solution for Easy Challenge #6
'Author: Keydrain
'Date: 04/02/15

'It appears that Visual Basic's best structure for this is Decimal and it has only 28 decimal places.
'So I don't want to write my own type to hold the larger data. 

Imports System.IO
Imports System.String
Imports System.Decimal

Class code

	Public Shared Sub Main()

		Dim GLans As Decimal = 4.0D
		Dim Nans As Decimal = 3.0D
		Dim number As Decimal = 3
		Dim specifier As String = "G"

		Console.Title = ("Easy Challenge #6")

		Do	
			GLans = GLans + GregoryLeibniz(number, specifier)
			Nans = Nans + Nilakantha(number, specifier)
			number = number + 4
		Loop While number < 4000000
			Console.WriteLine("")
			Console.WriteLine("GregoryLeibniz is    " + GLans.ToString(specifier))
			Console.WriteLine("Nilakantha is        " + Nans.ToString(specifier))
			Console.WriteLine("The answer should be 3.141592653589793238462643383279")
			Console.WriteLine("")

	End Sub

	Shared Function GregoryLeibniz(ByVal num As Decimal, ByRef specifier As String) as Decimal
		Dim value as Decimal = ((4/(num+2))-(4/num))
		'Console.WriteLine(value.ToString(specifier))
		return Convert.ToDecimal(value)
	End Function

	Shared Function Nilakantha(ByVal num As Decimal, ByRef specifier As String) as Decimal
		Dim value as Decimal = ((4/((num-1)*num*(num+1)))-(4/((num+1)*(num+2)*(num+3))))
		'Console.WriteLine(value.ToString(specifier))
		return Convert.ToDecimal(value)
	End Function
		
End Class