open System

let t = Console.ReadLine() |> int

let contiguousMaxSum (a : int array) =
  let mutable partialSum = a.[0]
  let mutable maxPartialSum = partialSum
  for i = 1 to a.Length - 1 do
    partialSum <- max (partialSum + a.[i]) a.[i]
    maxPartialSum <- max maxPartialSum partialSum
  maxPartialSum

let nonContiguousMaxSum a =
  let nonNegative = a |> Seq.filter (fun x -> x >= 0)
  if Seq.isEmpty nonNegative then
    Seq.max a
  else
    Seq.sum nonNegative

for _ in 1 .. t do
  let n = Console.ReadLine() |> int
  let a = Console.ReadLine().Split(' ') |> Array.map int
  printfn "%d %d" (contiguousMaxSum a) (nonContiguousMaxSum a)
