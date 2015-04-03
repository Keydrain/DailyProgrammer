'Solution to Easy Challenge #7
'Author: Keydrain
'Date: 04/02/15

Imports System.IO
Imports System.text

Class code

	Public Shared Sub Main()
		'Lists for converting'
		Dim Roman As Char() = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3","4","5","6","7","8","9"}
		Dim Morse As String() = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".----","..---","...--","....-",".....","-....","--...","---..","----.","-----"}
		Dim choice As Integer
		Dim response As String 'Running output'

		Console.WriteLine("")
		
		Console.Write("1: Translate Morse" & VBCrLf & "2: Translate Roman" & VBCrLf & "==> " )
		choice = Console.ReadLine()
		'If Translating from Morse to Roman'
		If choice = 1 Then
			Console.Write("Enter Text: ")
			Dim text As String = Console.ReadLine() 'Get the sentence'
			Dim words As String() = text.Split("/") 'Get words from the sentence'
			For Each word As String In words
				word = word.Trim(" ", "/") 'Clean spaces off the word'
				Dim letters As String() = word.Split(" ") 'Get each letter from each word from the sentence'
				For Each letter As String In letters
					Try
						Dim loc As Integer = Array.IndexOf(Morse, letter)
						response = response + Roman(loc)
					Catch e As exception
						Console.WriteLine(e.Message)
					End Try
				Next letter
			response = response + " "
			Next word
		'If Translating from Roman to Morse'
		Elseif choice = 2 Then
			Console.Write("Enter Text: ")
			Dim text As String = Console.ReadLine() 'Get the sentence'
			Dim words As String() = text.Split(" ") 'Get words from the sentence'
			For Each word As String In words
				Dim letter As Integer
				For letter = 0 to word.length-1 'Get each letter from each word from the sentence'
					Try
						Dim loc As Integer = Array.IndexOf(Roman, UCase(word(letter))) 'UCase makes uppercase'
						response = response + Morse(loc) + " "
					Catch e As exception
						Console.WriteLine(e.Message)
					End Try
				Next 
			response = response + " / " 'Formatting'
			Next word
			response = response.TrimEnd(" ", "/") 'Clean the ending / off'
		Else
			Console.WriteLine("You only got two options... Try running it again.")
		End If

		Console.WriteLine(response)
		Console.WriteLine("")

	End Sub

End Class


