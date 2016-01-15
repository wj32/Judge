open System

let P = 1000000007L
let t = Console.ReadLine() |> int

type Direction = Horizontal | Vertical

for _ in 1 .. t do
  match Console.ReadLine().Split(' ') |> Array.map int64 with
  | [|m; n|] ->
    let costs =
      [ Console.ReadLine().Split(' ') |> Seq.map (fun s -> (int64 s, Horizontal))
      ; Console.ReadLine().Split(' ') |> Seq.map (fun s -> (int64 s, Vertical)) ]
      |> Seq.concat
      |> Seq.sortByDescending fst
      |> Seq.toList
    let rec makeCuts acc hCuts vCuts remaining =
      match remaining with
      | [] -> acc
      | (cost, Horizontal) :: remaining -> makeCuts ((acc + ((vCuts + 1L) * cost) % P) % P) (hCuts + 1L) vCuts remaining
      | (cost, Vertical) :: remaining -> makeCuts ((acc + ((hCuts + 1L) * cost) % P) % P) hCuts (vCuts + 1L) remaining
    printfn "%d" (makeCuts 0L 0L 0L costs)
  | _ ->
    failwith "Invalid input"
