for _ in {1 .. stdin.ReadLine() |> int} do
  let n = stdin.ReadLine() |> int
  seq {
    for k = 1 to n |> float |> sqrt |> int do
      if n % k = 0 then
        yield k
        if k <> n / k then
          yield n / k
  }
  |> Seq.filter (fun k -> k % 2 = 0)
  |> Seq.length
  |> printfn "%d"
