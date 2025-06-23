Função: char* cadastro()
100% C ansi
windows/linux

A função `cadastro()` permite escolher entre **Cadastrar** ou **Fazer Login** de um usuário.
Ela recebe três parâmetros:

    char L_C     // indica se é login ou cadastro ('L' ou 'C')
    char nome[]  // nome do usuário
    char senha[] // senha do usuário

Após a validação dos dados, a função pode retornar uma entre 8 mensagens predefinidas, indicando o resultado da operação.

-----------------------
Modo de funcionamento:
-----------------------

• Se `L_C == 'C'`, será feito o **cadastro**:
    - A função criará um arquivo com o nome do usuário, adicionando `.txt` no final.
    - Esse arquivo conterá apenas a senha informada.
    - Se o arquivo já existir, o cadastro será recusado.

• Se `L_C == 'L'`, será feito o **login**:
    - A função tentará abrir o arquivo com o nome do usuário (`nome.txt`).
    - Ela então lerá a senha salva e comparará com a senha fornecida.

• Qualquer outro caractere em `L_C` é tratado como erro.

-----------------------
Observações:
-----------------------

- [Atenção] O arquivo será salvo na mesma pasta onde o programa estiver sendo executado.
- Não é necessário executar como administrador, exceto se a pasta tiver restrições de permissão (depende do sistema operacional).

-----------------------
Parâmetros:
-----------------------

- `char nome[]`: nome do usuário
- `char senha[]`: senha do usuário
- `char L_C`: 'L' para login, 'C' para cadastro

-----------------------
Retornos possíveis:
-----------------------

| Código | Retorno                                                    | Significado                                      |
|--------|------------------------------------------------------------|--------------------------------------------------|
| 1      | `"nome_existente"`                                         | Nome já está cadastrado                          |
| 2      | `"usuario_cadastrado"`                                     | Cadastro feito com sucesso                       |
| 3      | `"usuario_logado"`                                         | Login feito com sucesso                          |
| 4      | `"usuario_nao_cadastrado_ou_arquivo_nao_encontrado"`       | Nome não cadastrado ou arquivo não encontrado    |
| 5      | `"senha_incorreta"`                                        | Senha errada                                     |
| 6      | `"arquivo_vazio"`                                          | Arquivo existe mas está vazio                    |
| 7      | `"parametro_[L_C]_errado"`                                 | Valor inválido para `L_C`                        |
| 8      | `"erro_no_arquivo"`                                        | Erro ao criar ou abrir o arquivo                 |
