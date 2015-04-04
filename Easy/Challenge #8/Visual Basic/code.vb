'Solution to Easy Challenge #8
'Author: Keydrain
'Date: 04/04/15

Imports System.IO

Class code

	Public Shared Sub main()

		Dim bottles As Integer = 99

		Console.WriteLine("")

		Do
			Console.WriteLine(bottles & " bottles of beer on the wall, " & bottles & " bottles of beer.")
			bottles = bottles - 1
			If bottles = 0 Then
				Console.WriteLine("Take one down and pass it around, no more bottles of beer on the wall.")
			Else
				Console.WriteLine("Take one down and pass it around, " & bottles & " of beer on the wall.")
			End If
			Console.WriteLine("")
		Loop While bottles > 0

		Console.WriteLine("No more bottles of beer on the wall, no more bottles of beer.")
		Console.WriteLine("Go to the store and buy some more, 99 bottles of beer on the wall.")
		Console.WriteLine("")

	End Sub

End Class