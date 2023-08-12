### reasonreact-dream-fullstack

This project demonstrates a api/client style fullstack app
With melange and reason-react for the frontend and Dream for the API

### Get started

We have a Makefile for dune stuff and regular old npm for the JS stuff

```shell
make init # create opam switch and install dependancies
npm i
```

If npm produces an error about mismatched React versions use option `--legacy-peer-deps`

When running `make init`, you may encounter an error like this:

```
[ERROR] Could not determine which packages to install for this switch:
  * Missing dependency:
    - melange >= 1.0.0
    no matching version
```

To address this, first run `opam update`, then rerun `make init`.

--- 

I'm using vscode because it's so easy, I'm not doing an opam switch in the project, I just have a global switch 

---

#### Development build

The front and back end Reason is compiled at the same time

```shell
make watch
# dune build --watch
```

The API doesn't hot reload so when you make a change you'll have to restart it

```shell
make serve
# dune exec ... /server/../_build/default/server/server.exe
```

Webpack handles the JS output from melange, using the webpack server gets us hot-reloading

Or you could use your favourite bundler

```shell
npm run dev
# webpack ... ./_build/default/src/output/src/ReactApp.js
```

---

#### Production build

Cancel all your terminal processes

```shell
make build
npm run bundle
```

To try it out you can simply execute the binary, as long as it can find /public you're good to go

```shell
$ ./_build/default/server/server.exe
```

---

### Notable Dependancies

#### ReasonReact

I've used melange and reason-react via opam

[melange-re/melange](https://github.com/melange-re/melange)

[reasonml/reason-react](https://github.com/reasonml/reason-react)

#### Decco

[reasonml-labs/decco](https://github.com/reasonml-labs/decco)

The Decco ppx for generating Json serialisers is actually amazing to use, compared to the alternatives. I haven't got it behaving properly yet because it works with `bsconfig.json` which I am not doing, doesn't have its own dune file so I've added one to node_modules by hand. I really want it to work, perhaps I've done this wrong? I'm no good at lisp or dune files

```lisp
; /node_modules/decco/dune
(library
 (name decco)
 (kind ppx_rewriter))
```

#### Webpack lol

I don't eject config or do anything funny, it's super simple, in this case even easier than parcel, please change it as per your preference
