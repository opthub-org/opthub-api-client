# OptHub API

OptHubの公開REST APIです。
ユーザがプログラム中から解の提出・取得操作などを呼び出す自動化用途を想定しています。

* `opthub-spec.yaml`

    OptHub公開APIのOpenAPI仕様書です。
    公開APIの仕様変更の際は、このファイルを編集してください。

    * *Swagger UI* 導入までの暫定:
        [Swaggerの公式エディタ](https://editor.swagger.io/)にこのファイルの内容を入力すると、
        API仕様がわかりやすく表示されます。

以下のスクリプトの実行にはdockerのインストールが必要です。

* `codegen-{python,cpp,c,java,...}.sh`

    `opthub-spec.yaml`で記述された仕様に基づき、各言語のAPIクライアントコードを自動生成するスクリプトです。
    実行すると、`opthub-api-client-{python,cpp,c,java,...}`ディレクトリが出力されます。

    もし生成物に何か修正を加えたい場合、
    生成物のgitサブモジュール (`opthub-api-client-.../`) を直接編集するのではなく（仕様変更で再生成する際にまた1から編集しなおすことになるため）、パッチファイルを作成し、シェルスクリプト内で`patch`コマンドなどでパッチを当てる形をとってください。

* `codegen-all.sh`

    対応している全言語向けのコード及びSwagger UIの静的サイトを一括生成するスクリプトです。

    最初にコミットメッセージの入力を促されるので、何か文字列を入力すると
    全言語のgitサブモジュールリポジトリにコミットとpushが実行されます。

    何も文字を入力しない（空文字列を入力する）と、生成のみの実行になります。

    正しく動作しない生成物をpushしてしまわないように、仕様書を変更した後はまず空文字列で生成のみの実行を試すとよいです。

* `generate-ui.sh`

    Swagger UI（REST APIの仕様のWebドキュメント）の静的サイトを自動生成します。

* `run-swagger-editor.sh`

    API仕様書の.yamlを書く際、エラーチェックや可視化をしてくれるWebツールであるSwagger Editorを http://localhost:80/ で起動します。
