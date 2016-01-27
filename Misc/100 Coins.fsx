// 100 coins are placed in a circle, labeled from 1 to 100 clockwise. Starting at coin 1, we move
// clockwise and toss each coin. If it lands tails, we keep it. If it lands heads, we remove it.
// Continuing this process, almost surely we end up with one coin. What is the expected value of its
// label?

open System
open System.Collections.Generic

let random = Random()

let experiment n =
  let coins = LinkedList<int>({1 .. n})
  let rec loop (node : LinkedListNode<int>) =
    if coins.Count > 1 then
      let next = if node.Next <> null then node.Next else coins.First
      if random.NextDouble() > 0.5 then
        coins.Remove(node)
      loop next
    else
      ()
  loop coins.First
  coins.First.Value

let histogram f n =
  let counts = Dictionary<_, int>()
  for i = 1 to n do
    let value = f ()
    let mutable count = 0
    if counts.TryGetValue(value, &count) then
      counts.[value] <- count + 1
    else
      counts.Add(value, 1) |> ignore
  counts |> Seq.map (|KeyValue|) |> Map.ofSeq

let expectation hist =
  hist
  |> Map.toSeq
  |> Seq.fold
    (fun (totalSum, totalCount) (key, count) -> (totalSum + key * count, totalCount + count))
    (0, 0)
  |> (fun (totalSum, totalCount) -> float totalSum / float totalCount)

let dist = histogram (fun () -> experiment 100) 1000000
let distCounts = dist |> Map.toSeq |> Seq.map snd |> Seq.toList

// Other random stuff

module OtherExperiments =
  let rollWithBust bust reroll =
    let rec loop acc =
      let acc' = acc + random.Next(1, 7)
      if acc' >= bust then
        0
      else
        if reroll acc' then
          loop acc'
        else
          acc'
    loop 0
  let breakStickTriangle () =
    let (x, y) = (random.NextDouble(), random.NextDouble())
    let (x, y) = if x < y then (x, y) else (y, x)
    let (a, b, c) = (x, y - x, 1. - y)
    let success =
      match a, b, c with
      | large, small1, small2 when a >= b && a >= c -> small1 + small2 >= large
      | small1, large, small2 when b >= a && b >= c -> small1 + small2 >= large
      | small1, small2, large when c >= a && c >= b -> small1 + small2 >= large
      | _ -> failwith "Invalid state"
    if success then 1 else 0
