open System
open System.Collections.Generic

let n = Console.ReadLine() |> int

let grid =
  {1 .. n}
  |> Seq.map (fun _ -> Console.ReadLine())
  |> Seq.toArray

match Console.ReadLine().Trim().Split(' ') |> Array.map int with
| [|a; b; c; d|] ->
  let start = (a, b)
  let goal = (c, d)
  let directions = [(1, 0); (-1, 0); (0, 1); (0, -1)]
  let unseen = Queue<(int * int) * int>()
  let seen = HashSet<int * int>()
  
  unseen.Enqueue((start, 0))
  seen.Add(start) |> ignore
  
  let rec loop () =
    if unseen.Count <> 0 then
      let (point, distance) = unseen.Dequeue()
      if point = goal then
        Some distance
      else
        let add p =
          if not (seen.Contains(p)) then
            seen.Add(p) |> ignore
            unseen.Enqueue((p, distance + 1))
        let rec go ((dx, dy) as d) ((x, y) as p) =
          let (x', y') as p' = (x + dx, y + dy)
          if 0 <= x' && x' < n && 0 <= y' && y' < n && grid.[x'].[y'] <> 'X' then
            add p'
            go d p'
        for direction in directions do
          go direction point
        loop ()
    else
      None
  
  match loop () with
  | Some distance -> printfn "%d" distance
  | None -> printfn "Unreachable"
| _ ->
  failwith "Invalid input"
