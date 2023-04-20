class Game:
    def __init__(self, nome=None, genero=None, plataforma=None,
        ano=None, classificacao=None, preco=None, midia=None,
        tamanho=None, produtora=None):
        self.nome = nome
        self.genero = genero
        self.plataforma = plataforma
        self.ano = ano
        self.classificacao = classificacao
        self.preco = preco
        self.midia = midia
        self.tamanho = tamanho
        self.produtora = produtora

with open('test.txt', 'r', encoding = "utf-8") as fp:
    conteudo = fp.read()
    print(f'{conteudo}')
    
variaveis = conteudo.split("\n")
for variaveis in variaveis:
    print(f'{variaveis}')

fp.close()