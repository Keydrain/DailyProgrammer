'Solution for Easy Challenge #5
'Author: Keydrain
'Date: 04/01/15
'
'Includes Extra Credit file support

Imports System.IO

Class code

	Public Shared Sub Main()
		Dim realname As String
		Dim realpass As String
		Dim name As String
		Try
			ReadIn(realname, realpass)
			Console.Title = ("Easy Challenge #5")
			Dim tries As Integer = 0
			Do
				Console.Write("Please enter username: ")
				name = Console.ReadLine
				Console.Write("Please enter password: ")
				Dim pass As String = Console.ReadLine
				'Console.WriteLine("Your name is " + name + " and your pass is " + pass)
				If name = realname Then
					If pass = realpass Then
						tries = 10
					Else
						Console.WriteLine("Password is incorrect.")
						tries = tries + 1
					End If
				Else	
					Console.WriteLine("Username is incorrect.")
					tries = tries + 1
				End If
				Console.WriteLine()
			Loop While tries < 3
			If tries = 10 Then
				Console.WriteLine("Greetings " + name + "!")
			Else
				Console.WriteLine("Permission Denied. Too many attempts.")
			End If
			Console.WriteLine()
		catch e As Exception
			Console.WriteLine(e.Message)
		End Try
	End Sub

	Shared Sub ReadIn(ByRef realname As String, ByRef realpass As String)
		Try
			Using sr As New StreamReader("in.log")
				realname = sr.ReadLine()
				realpass = sr.ReadLine()
			End Using
		Catch e As Exception
			Console.WriteLine("Does in.log have the username on the first line and the password on the second line?")
			Console.WriteLine(e.Message)
		End Try
	End Sub

End Class