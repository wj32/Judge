open System
open System.Collections.Generic

module NoPrefixTrie =
  type T = End | Node of Dictionary<char, T>
  
  let create () = Node (Dictionary<char, T>())
  
  let add (s : string) trie =
    let rec add i trie =
      match trie with
      | End -> false
      | Node children ->
        match i = s.Length - 1, (children.ContainsKey(s.[i])) with
        | true, false -> children.Add(s.[i], End); true
        | true, true -> false
        | false, childExists ->
          if not childExists then
            children.Add(s.[i], Node (Dictionary<char, T>()))
          add (i + 1) children.[s.[i]]
    add 0 trie

let n = Console.ReadLine() |> int
let trie = NoPrefixTrie.create ()

let rec loop i =
  if i > n then
    None
  else
    let s = Console.ReadLine()
    if not (NoPrefixTrie.add s trie) then
      Some s
    else
      loop (i + 1)
    
match loop 1 with
| Some badString ->
  printfn "BAD SET"
  printfn "%s" badString
| None ->
  printfn "GOOD SET"
