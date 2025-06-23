char* cadastro(char L_C, char nome[99], char senha[99]){
    char linha[256];
    char novo_nome[99];
    strcpy(novo_nome, nome);
    strcat(novo_nome, ".txt");

    if(L_C == 'L' || L_C == 'l'){
        FILE *arquivo = fopen(novo_nome, "r");
        if (arquivo == NULL) return "usuario_nao_cadastrado_ou_arquivo_nao_encontrado";

        if (fgets(linha, sizeof(linha), arquivo) != NULL){
            linha[strcspn(linha, "\r\n")] = '\0';
            fclose(arquivo);
            if(strcmp(linha, senha) == 0){
                return "usuario_logado";
            } else {
                return "senha_incorreta";
            }
        } else {
            fclose(arquivo);
            return "arquivo_vazio";
        }
    } else if(L_C == 'C' || L_C == 'c'){
        FILE *verifica = fopen(novo_nome, "r");
        if (verifica != NULL) {
            fclose(verifica);
            return "nome_existente";
        }
        FILE *criar = fopen(novo_nome, "w");
        if (criar == NULL) return "erro_no_arquivo";
        fprintf(criar, "%s", senha);
        fclose(criar);
        return "usuario_cadastrado";
    } else {
        return "parametro_[L_C]_errado";
    }
}