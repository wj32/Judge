for _ in {1 .. stdin.ReadLine() |> int} do
  let s = stdin.ReadLine()
  let a = s |> Seq.filter ((=) 'a') |> Seq.length
  let b = s |> Seq.filter ((=) 'b') |> Seq.length
  let c = s |> Seq.filter ((=) 'c') |> Seq.length
  let answer =
    match a, b, c with
    | x, 0, 0 | 0, x, 0 | 0, 0, x -> x
    | a, b, c when (a + b) % 2 + (a + c) % 2 + (b + c) % 2 = 0 -> 2
    | _ -> 1
  printfn "%d" answer
