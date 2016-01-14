open System

let P = 1000000007I

let t = Console.ReadLine() |> int

for _ in { 1 .. t } do
  let n = bigint.Parse(Console.ReadLine())
  printfn "%A" ((n * n) % P)
