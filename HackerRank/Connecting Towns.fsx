open System

let P = 1234567

let t = Console.ReadLine() |> int

for _ in 1 .. t do
  let n = Console.ReadLine() |> int
  Console.ReadLine().Split(' ')
  |> Seq.map int
  |> Seq.fold (fun acc m -> (acc * m) % P) 1
  |> printfn "%d"
