open System

let t = Console.ReadLine() |> int

for _ in { 1 .. t } do
  let n = Console.ReadLine() |> int
  let a =
    seq { 1 .. n }
    |> Seq.map (fun _ -> Console.ReadLine().ToCharArray())
    |> Seq.toArray
  let b = a |> Array.map Array.sort
  let sorted =
    seq { 0 .. n - 1 }
    |> Seq.forall (fun j ->
      seq { 1 .. n - 1 }
      |> Seq.forall (fun i ->
        b.[i - 1].[j] <= b.[i].[j]))
  printfn "%s" (if sorted then "YES" else "NO")
