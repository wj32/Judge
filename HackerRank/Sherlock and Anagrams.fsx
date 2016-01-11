open System

let frequencies (s : string) =
  seq
    { for i in 0 .. s.Length - 1 do
        for j in i .. s.Length - 1 do
          let f = Array.zeroCreate 26
          for k in i .. j do
            let index = int s.[k] - int 'a'
            f.[index] <- f.[index] + 1
          yield f
    }

let t = Console.ReadLine() |> int

for i in 1 .. t do
  Console.ReadLine()
  |> frequencies
  |> Seq.groupBy id
  |> Seq.fold
    (fun acc (key, seq) ->
      let n = Seq.length seq
      acc + n * (n - 1) / 2)
    0
  |> printfn "%d"
