open System

let t = Console.ReadLine() |> int

for _ in 1 .. t do
  match Console.ReadLine().Split(' ') |> Array.map int with
  | [|n; k|] ->
    let a = Console.ReadLine().Split(' ') |> Array.map int
    let b = Console.ReadLine().Split(' ') |> Array.map int
    let answer =
      Array.zip (Array.sort a) (Array.sortDescending b)
      |> Array.forall (fun (x, y) -> x + y >= k)
    printfn "%s" (if answer then "YES" else "NO")
  | _ ->
    failwith "Invalid input"
