let digitSum = Seq.map (fun c -> bigint (int c - int '0')) >> Seq.sum

let rec superDigit n = if n < 10I then n else superDigit (n |> string |> digitSum)

match stdin.ReadLine().Split(' ') with
| [|n; k|] ->
  printfn "%A" (superDigit (bigint.Parse k * digitSum n))
| _ ->
  failwith "Invalid input"
