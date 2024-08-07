# OptHub API

OptHubの公開REST APIです。
ユーザがプログラム中から解の提出・取得操作などを呼び出す自動化用途を想定しています。

* `opthub-spec.yaml`

    OptHub公開APIのOpenAPI仕様書です。
    公開APIの仕様変更の際は、このファイルを編集してください。

    * *Swagger UI* 導入までの暫定:
        [Swaggerの公式エディタ](https://editor.swagger.io/)にこのファイルの内容を入力すると、
        API仕様がわかりやすく表示されます。

* `codegen-{python,cpp,c,java,...}.sh`

    `opthub-spec.yaml`で記述された仕様に基づき、各言語のAPIクライアントコードを自動生成するスクリプトです。
    実行すると、`opthub-api-client-{python,cpp,c,java,...}`ディレクトリが出力されます。

    実行には`docker`のインストールが必要です。

    もし生成物に何か修正を加えたい場合、
    生成物のgitサブモジュール (`opthub-api-client-.../`) を直接編集するのではなく（仕様変更で再生成する際にまた1から編集しなおすことになるため）、パッチファイルを作成し、シェルスクリプト内で`patch`コマンドなどでパッチを当てる形をとってください。

* `codegen-all.sh`

    対応している全言語向けにコードを一括生成するスクリプトです。
