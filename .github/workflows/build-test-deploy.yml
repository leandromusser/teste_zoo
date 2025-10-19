name: Build, Test e Deploy no Cloudflare Pages

on:
  push:
    branches:
      - "**"
  pull_request:

jobs:
  test:
    name: Roda os testes
    runs-on: ubuntu-latest

    steps:
      - name: Checkout do repositório
        uses: actions/checkout@v4

      - name: Compila e executa os testes C
        run: |
          sudo apt-get update
          sudo apt-get install -y build-essential
          gcc -Itests src/zoo.c tests/zoo_test.c -o zoo_test.out
          ./zoo_test.out

  build:
    name: Build do WebAssembly
    runs-on: ubuntu-latest
    if: github.ref == 'refs/heads/master'
    needs: test

    steps:
      - name: Checkout do repositório
        uses: actions/checkout@v4

      - name: Instalação do Emscripten
        uses: mymindstorm/setup-emsdk@v14
        with:
          version: latest

      - name: Build do WebAssembly
        run: |
          mkdir -p page
          emcc -Isrc src/zoo.c -o page/index.html

      - name: Salva o WebAssembly para o job de deploy
        uses: actions/upload-artifact@v4
        with:
          name: wasm-build
          path: page/

  deploy:
    name: Deploy no Cloudflare Pages
    runs-on: ubuntu-latest
    needs: build

    steps:
      - name: Download do WebAssembly do job anterior
        uses: actions/download-artifact@v4
        with:
          name: wasm-build
          path: page/

      - name: Deploy no Cloudflare Pages
        uses: cloudflare/wrangler-action@v3
        with:
          apiToken: ${{ secrets.CLOUDFLARE_API_TOKEN }}
          accountId: ${{ secrets.CLOUDFLARE_ACCOUNT_ID }}
          command: pages deploy ./page --project-name="teste-zoo"
