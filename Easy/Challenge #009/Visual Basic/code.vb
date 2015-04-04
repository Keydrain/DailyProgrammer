'Solution to Easy Challenge #009
'Author: Keydrain
'Date: 04/04/15

Imports System.IO

Class code
	
	Public Shared Sub main()

		Dim input As String()
		Dim text As String

		Console.WriteLine("")

		Console.Write("Enter numbers and/or letters to be sorted: ")
		text = Console.ReadLine()
		input = text.Split()

		Array.Sort(input) 'This feel like cheating'

		Console.Write("Sorted:")

		For Each item As String in input
			Console.Write(" " & item)
		Next

		Console.WriteLine(VBCRLF)

	End Sub

End class