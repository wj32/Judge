open System

let n = Console.ReadLine() |> int
let k = Console.ReadLine() |> int

let a =
  seq {1 .. n}
  |> Seq.map (fun _ -> Console.ReadLine() |> int)
  |> Seq.sort
  |> Seq.toArray

seq {0 .. n - k}
|> Seq.map (fun i -> a.[i + k - 1] - a.[i])
|> Seq.min
|> printfn "%d"
