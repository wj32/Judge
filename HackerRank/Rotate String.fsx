for _ in {1 .. stdin.ReadLine() |> int} do
  let s = stdin.ReadLine()
  {1 .. s.Length}
  |> Seq.scan (fun (acc : string) _ -> acc.Substring(1) + string acc.[0]) s
  |> Seq.tail
  |> (fun seq -> System.String.Join(" ", seq))
  |> printfn "%s"
