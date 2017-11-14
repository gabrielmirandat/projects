// how to
'https://start.spring.io/'


// tecnologias
gradle
groovy
spring X JEE
springboot
hibernate
flyway
spock
junit
rxjava


// @ (anotation)
@Deprecated 'não deve ser mais usado'
@Override 'metodo sobrescrito'
@Test 'método é teste no JUnit'

@Entity 'declara uma entidade do tipo relacional, como uma tabela, porém é uma classe java'
@Id 'define o identificador da tabela'
@SequenceGenerator 'forma de auto incremento de determinado campo'

@SpringBootApplication 'equivalente a @Configuration, @EnableAutoConfiguration e @ComponentScan com valores default
						indica uma classe de config que declara um ou mais métodos @Bean e trigger auto-configuration e scan de componente'
@EnableFeignClients 'faz scan no classpath do pacote da classe em que está definido
					no caso, seus cliente feign atuais não estão localizados no pacote BaseApplications'
@Bean 'bean do Spring
	   receita para criar novas instancias da classe definida pela definição da Bean
	   servem de injeção de dependência'
@GetMapping 'mapeia requisições HTTP GET em métodos específicos'
@RestController 'anotada como @Controller e @ResponseBody'
@Autowired 'marca um construtor. campo, método setter ou método de config pra ser autowired pelas facilidades de injeção de dependência do Spring'
@Value 'anotação no campo ou método/construtor para dar um valor padrão para o argumento afetado'
@PostMapping 'shortcut para @RequestMapping(method = RequestMethod.POST)'
@RequestBody 'indica que um parametro do método deve ser bound ao corpo do web request'
@RequestParam 'parametro direto do request HTTP, entra com /?'
@PathVariable 'parametro que é caminho comum da url, uma barra sem ?'
@ControllerAdvice 'especialização de @Component para classes que declaram métodos @ExceptionHandler, @InitBinder, ou @ModelAttribute compartilhados em múltiplas classes
 				   @Controller'
@Immutable 'marca entidade, coleção ou atributo como imutável'
@ExceptionHandler 'gerencia exceções em classes em classes ou métodos específicas de handler'

// simbolos ao lado do nome
C - classe 
I - interface
cadeado aberto ou fechado - público ou privado


// código
java.util.logging.Logger // mostra dados na tela


// principal
*aplicacao/ // camada da aplicacao
	build/ // arquivos class da compilacao
	build.gradle // arquivo de configs de compilacao e outros
	src/
		test/ // arquivos de teste da main/
		main/
			resources/ // arquivos do banco de dados e controle de versao do flyway
			groovy/
				aplicacao/
					*autuarrepresentacao/
						AutuarProcessoServico.groovy // servico para autuação
													 // contém processoServicoExterno, licitacaoRepository, contratoRepository, unidadeServico, relatorServicoExterno
													 // métodos autue, criarComando, montarTextoAssunto, podeDefinirRelator, getCodRelator
						// @Component
						AutuarRepresentacaoServicoAplicacao.groovy // tem um autuarProcessoServico
																   // a pre-autorização checa no banco se o usuario tem alguma Role (permissao)
																   // métodos autue, documentosPorIdsDocumentosGestao, documentosPorIds, dadosAutores, 
																   // dadosObjetos, dadosGerais, pesquiseRepresentacaoAutuadaComObjeto
						// @Service
						// @Transactional
    					// @PreAuthorize
						ComandoAutuarRepresentacao.groovy // DTO: "Data transfer objects " can travel between seperate layers in software 
														  // declara todas as classes, ComandoAutuarRepresentacao, AutorDto, ObjetoDto, DadosProcessoDto
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
						ConversorDtoEmAutorRepresentacao.groovy // apenas uma função de conversão
						ConversorDtoEmObjetoRepresentacao.groovy // apenas uma função de conversão
						CriarRepresentacaoServico.groovy // métodos criar, documentosIniciaisOrdenados, novoNumeroRepresentacao, novaRepresentacao
						// @Component
						// @Transactional
						DadosGeraisDto.groovy // DTO: "Data transfer objects " can travel between seperate layers in software 
											  // declara todas as classes, DadosGeraisDto, UnidadeTecnicaDto, 
											  // UnidadeResponsavelPorAgirDto, SubunidadeDto ,ConfidencialidadeDto
						// @JsonIgnoreProperties
						// @Immutable

					*criarcontrato/
						ComandoCriarContrato.groovy // apenas encapsula idNegocio, codUASG, descricao, valorTotalContratado
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
						// @JsonDeserialize
						ContratoDto.groovy // encapsula id, idNegocio, nomeOrgaoEntidade, idSituacao, codUASG, descricao, valorTotalContratado
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
						// @JsonDeserialize
						ConversorContratoEmDto.groovy // possui métodos de conversão converte, montaContratoDto, montaIdContratoDto, nomeOrgaoEntidade
						CriarContratoServicoAplicacao.groovy // possui métodos de criar, recuperePorIdentificador, crieIdentificadorContrato, recuperePorIds
						// @Service
						// @Transactional
						// @PreAuthorize
						IdContratoDto.groovy // encapsula dados de idOrgaoEntidade, numero, ano
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
					*criarlicitacao/
						ComandoCriarLicitacao.groovy // apenas encapsula idNegocio, codUASG, descricao, valorTotalEstimado
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
						// @JsonDeserialize
						LicitacaoDto.groovy // encapsula id, idNegocio, nomeOrgaoEntidade, idSituacao, codUASG, descricao, valorTotalEstimado
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
						// @JsonDeserialize
						ConversorLicitacaoEmDto.groovy // possui métodos de conversão converte, montaLicitacaoDto, montaIdLicitacaoDto, nomeOrgaoEntidade
						CriarLicitacaoServicoAplicacao.groovy // possui métodos de criar, recuperePorIdentificador, dadosModalidades, crieIdentificadorLicitacao,
															  // recuperePorIds, recuperePorId
						// @Service
						// @Transactional
						// @PreAuthorize
						IdLicitacaoDto.groovy // encapsula dados de idOrgaoEntidade, numero, ano e idModalidade
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
					*documento/
						DocumentoConteudoDto.groovy // encapsula conteudoBase64 e nomeArquivo
						// @JsonIgnoreProperties
						// @Immutable
						DocumentoServicoAplicacao.groovy // possui método obterConteudoDocumento pelo id do documento
						// @Service
						// @PreAuthorize
					*editarrepresentacao/
						ComandoAtualizarRepresentacao.groovy // apenas encapsula id, autores e objetos
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
						ConversorRepresentacaoEmDto.groovy // possui metodos converte, montarDtoComposto, getDocumentos, getAutores, getObjetos, getDadosGerais
						EditarRepresentacaoServicoAplicacao.groovy // possui métodos getRepresentacaoComIdProcesso, getRepresentacao, atualize
						// @Service
						// @PreAuthorize
						IdRepresentacaoDto.groovy // apenas encapsula id da representacao
						RepresentacaoDto.groovy // possui classes RepresentacaoDto, NumeroRepresentacaoDto, DadosGeraisDto, DocumentoDto, AutorDto, SignatarioDto,
												// ObjetoDto, DadosObjetoNaoClassificadoDto
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
						UnidadeJurisdicionadaServico.groovy // tem LicitacaoRepository e ContratoRepository
															// possui métodos recuperarIdsUnidadesJurisdicionadas, recuperarIdsOrgaosEntidadesLicitacaoEContrato
						// @Service
					*pessoaqualificada/
						MunicípioDto.groovy // apenas encapsula uma uf e recebe Map<String, Object> props no construtor
						// @JsonIgnoreProperties
						// @JsonCreator
						PessoaDto.groovy // encapsula id, nome, cpfOuCnpj, municipioLocalizacao, possuiCaraterPublico, incluirDaRFB
						PessoaQualificadaDto.groovy // encapsula idPessoa, nomePessoa, exigeNumeroFiscalizacao
						// @Builder
						// @Immutable
						PessoaQualificadaServicoAplicacao.groovy // tem pessoaQualificadaRepository e pessoaServicoExterno
																 // métodos pesquisePorTipoQualificacao, pesquisePorCpf, pesquisePorCnpj, 
																 // incluirPessoaPorCpfDaReceita, pesquisePorParteNomeOrgao, pessoasPorIdsOrdenadas
						// @Service
						// @Transactional
						// @PreAuthorize
					*processo/
						ProcessoServicoAplicacao.groovy // possui ProcessosServicoExterno, AutenticacaoServicoExterno e urlSistemaLegado
														// métodos obterIdProcessoPorNumeroAnoDV, obterLinkProcessoEGestao
						// @Service
						// @Value
						// @PreAuthorize
					*servicoexterno/
						AutenticacaoServicoExterno.groovy // método autentica e autenticaLoginIntegrado
						// @FeignClient
						// @PostMapping
						// @RequestBody
						ComandoAutuacaoProcesso.groovy // encapsula codTipoProcesso, codUnidadeTecnica, codSubunidadeTecnica, codUnidadeRespAgir, 
													   // codSubunidadeRespAgir, codTipoConfidencialidade, codClasseAssunto, textoComplementoAssunto, codRelator, 
													   // codsUnidadesJurisdicionadas, codsDocumentosAJuntar, codsResponsaveis, codsInteressados
						// @JsonIgnoreProperties
						// @Builder
						// @Immutable
						DocumentosDto.groovy // encapsula lista de documentos
						// @JsonIgnoreProperties
						// @Immutable
						DocumentoServicoExterno.groovy // tem mapeamentos para documentosPorIds(), documentosPorIdsDocumentosGestao(), obterConteudo()
						// @FeignClient
						// @GetMapping
						// @RequestParam
						// @PathVariable
						PessoaServicoExterno.groovy // muitos mapeamentos para pessoaFisicaPorCpf(), pessoaJuridicaPorCnpj(), pessoaJuridicaPorCnpjReceita(), 
													// incluirPessoaJuridicaDaReceita(), orgaoPorParteNome(), pessoasPorIds(), pessoasJuridicasPorIds()
						// @FeignClient
						// @GetMapping
						// @PathVariable
						// @RequestParam
						ProcessoDto.groovy // encapsula cod, confidencialidade, codUnidadeResponsavelPorAgir, codUnidadeResponsavelTecnica, 
										   // codSubunidadeResponsavelPorAgir,  codSubunidadeResponsavelTecnica
						// @JsonIgnoreProperties
						// @JsonCreator
						ProcessosServicoExterno.groovy // mapeamentos para processoPorNumeroAnoDV(), autuarProcesso(), processoPorCodigo()
						// @FeignClient
						// @GetMapping
						// @RequestParam
						// @RequestBody
						RelatorServicoExterno.groovy // mapeamento para recuperarCodigoDoRelatorSugerido()
						// @FeignClient
						// @GetMapping
						// @PathVariable
						// @RequestParam
						SubUnidadesDto.groovy // apenas encapsula subUnidades
						// @JsonIgnoreProperties
						// @Immutable
						SubUnidadeTecnicaExternaDto.groovy // apenas encapsula id, nome, sigla, idUnidadeSuperior, idNivel, nivelSuperior
						// @JsonIgnoreProperties
						// @Immutable
						UnidadesTecnicasDto.groovy // retorna lista de unidades
						// @JsonIgnoreProperties
						// @Immutable
						UnidadeTecnicaExternaDto.groovy // armazena dados e cria JSON de id e nome
						// @JsonIgnoreProperties
						// @JsonCreator
						// @JsonProperty
						UnidadeTecnicaServicoExterno.groovy // mapeamentos para os métodos obterUnidades(), obterUnidadePorId() e obterSubUnidades()
						// @FeignClient
						// @GetMapping
						// @PathVariable
					*util/
						*perfil/
							PerfilUsuario.groovy // atributos SEPARADOR_OBJETO, PERFIL_DESENVOLVEDOR, PERFIL_DESENVOLVEDOR_ATUALIZADOR, PERFIL_AUTUADOR_PROCESSO
												 // metodos desenvolvedor, desenvolvedorAtualizador, desenvolvedores, autuarProcesso e autuadorProcessoUnidade
							// @Component
						ConversorValorMonetario.groovy // métodos paraBigDecimal e paraString
						DesserializadorBigDecimal.groovy // método deserialize
						// @Override
						SerializadorBigDecimal.groovy // método serialize
						// @Override
				

				*config/
					*audithook/
						HibernateConfiguration.groovy // A JPA define um meio de mapeamento objeto-relacional para objetos Java simples e comuns (POJOs), 
													  // denominados beans de entidade
													  // é um HibernateJpaAutoConfiguration
													  // usa hibernate.ejb.interceptor
						// @Autowired
						// @Override
						PkgsOracleInterceptor.groovy  // chama função atribuiUsuarioParaTriggerAuditLegado()
						 							  // onSave, onDelete, onFlushDirty, preFlush
						 							  // atribuiUsuarioParaTriggerAuditLegado, geraEstatisticasAcesso, usuarioRealLogado
						// @Component
						// @Autowired
    					// @Lazy
    					// @Override
    					// @SuppressWarnings

					*undertow/
						DataSourceConfig.groovy // retorna DataSourceBuilder.create().build()
						// @Configuration
						// @Bean
						// @ConfigurationProperties
						UndertowHttp2BuilderCustomizer.groovy // customiza adicionando a opção de servidor HTTP2
						// @Override
						UndertowHttp2Customizer.groovy // usa factory.addBuilderCustomizers()
						// @Component
						// @Override


				*infra/
					*flyway/
						FlywayConfiguration.groovy // chama 2 beans, um de inicialização e outro de callback do flyway
						// @Bean

					*seguranca/
						ConfiguracaoDocumentoAutenticacaoRest.groovy // bean que retorna RestClientHttpRequestInterceptorDeDocumento()
						// @Configuration
						// @Bean
						ConfiguracaoPessoaAutenticacaoRest.groovy // bean que retorna RestClientHttpRequestInterceptorDePessoa()
						// @Configuration
						// @Bean	
						ConfiguracaoPessoaWrapperAutenticacaoRest.groovy // bean que retorna RestClientHttpRequestInterceptorDePessoaWrapper()
						// @Configuration
						// @Bean
						ConfiguracaoProcessoAutenticacaoRest.groovy // bean que retorna RestClientHttpRequestInterceptorDeProcesso()
						// @Configuration
						// @Bean
						ConfiguracaoUnidadeTecnicaAutenticacaoRest.groovy // bean que retorno RestClientHttpRequestInterceptorDeUnidadeTecnica()
						// @Configuration
						// @Bean
						CORSConfig.groovy // adiciona CORS na aplicação, para dar autorização a aplicação no browser
						// @Configuration
						// @Autowired
						// @Override
						DadosAutenticacao.groovy // apenas encapsula username, password, usuarioLogadoServicoOrigem, tokenLoginIntegrado
						DadosAutenticacaoLoginIntegrado.groovy // apenas encapsula codRecursoComputacional, tokenJwt
						DadosAutenticacaoRecurso.groovy // apenas encapsula dadosAutenticacao, codRecursoComputacional, codsRecursosComputacionaisAdicionais
						// @JsonUnwrapped
						RestClientHttpRequestInterceptor.groovy // faz a autorização do usuário, pegando o /auth e body
																// retorna os dados da autenticação, username, password e usuarioLogadoServiçoOrigem
																// uma função que retorna o login do usuário logado
						// @Autowired
						// @Override
						RestClientHttpRequestInterceptorDeDocumento.groovy // retorna 263L
						// @Override
						RestClientHttpRequestInterceptorDePessoa.groovy // apenas retorna 189L
						// @Override
						RestClientHttpRequestInterceptorDePessoaWrapper.groovy // retorna 274L
						// @Override
						RestClientHttpRequestInterceptorDeProcesso.groovy // retorna 1L
						// @Override
						RestClientHttpRequestInterceptorDeUnidadeTecnica.groovy // retorna 274L
						// @Override
						RestSecurityConfig.groovy // autoriza o request de outras aplicações no serviço, como /management, /api/v1/auth e outros
						// @Order(HIGHEST_PRECEDENCE)
						// @Override
						TokenLoginIntegradoServico.groovy // tem um string do token
						// @Immutable
						// @Builder
						TokenServico.groovy // apenas encapsula o tokenJwt
						// @Immutable
						UsuarioAutenticadoHelper.groovy // retorna usuario autenticado ou null
						
						
					*rest/
						AutenticacaoRest.groovy // realiza autenticação do usuário (Post em auth)
						// @RestController
						// @Autowired
						// @Value
						// @PostMapping
						// @RequestBody
						AutuarRepresentacaoRest.groovy // autua a representacao (Gets para documentos de gestão e representação, autores, objetos, dados gerais, objeto, 
													   // Post para autuar )
						// @RestController
						// @GetMapping
						// @RequestParam
						// @PathVariable
						// @PostMapping
						// @RequestBody
						ControladorExcecao.groovy // gerencia exceções
						// @ControllerAdvice
						// @Immutable
						// @ExceptionHandler
						CriaContratoRest.groovy // cria e recupera objetos Contrato (no Post/criar precisa de um body, no Get/recuperar parametros de id, numero, ano)
						// @RestController
						// @PostMapping
						// @RequestBody
						// @GetMapping
						// @RequestParam
						CriarLicitacaoRest.groovy // cria e recupera licitações (no Post/criar precisa de um body, 
												  // no Get/recuperar pode ser parametros idOrgao, numero, ano, idModalidade ou variavel de caminho id
												  // tem um Get para as modalidades da licitacao também)
						// @RestController
						// @PostMapping
						// @RequestBody
						// @GetMapping
						// @RequestParam
						// @PathVariable
						DocumentoRest.groovy // apenas obtem documentos (no Get/recuperar por variavel de caminho id)
						// @RestController
						// @GetMapping
						// @PathVariable
						PessoaQualificadaRest.groovy // apenas recupera pessoas 
													 // no Get/recuperar por parametros tipoQualificacaoId ou por cpf ou por cnpj ou por nome
						// @RestController
						// @GetMapping
						// @RequestParam
						ProcessoRest.groovy // recupera processos (no Get/recuperar por parametros numero, ano, digito verificador)
						// @RestController
						// @GetMapping
						// @RequestParam
						RepresentacaoRest.groovy // recupera ou atualiza uma representação por completo 
												 // no Get/recuperar por parametros de idProcesso ou variavel de caminho id
												 // tem um Get para id da Representação por parametro id 
												 // no Post/atualizar precisa de um body
						// @RestController
						// @GetMapping
						// @RequestParam
						// @PathVariable
						// @RequestBody
				

				*sanityrest/
					Http2ServiceRest.groovy  // controlador REST / mapeia "/", "/entity-flow", "/push"
					// @RestController
					// @GetMapping
				

				*RepresentacaoMain.groovy // roda aplicacao SpringBoot / cria um Bean
				// @SpringBootApplication
				// @EnableFeignClients
				// @Bean


*dominio/ // camada de dominios
	build/ // arquivos class da compilacao
	src/
	build.gradle // arquivo de configs de compilacao


// outros
*gradle/ // arq de propriedades do GRADLE WRAPPER
*k8s/ // arq de config de deploy e outros do RANCHER
*representacao/ // arq de propriedades do SISTEMA REPRESENTACAO

// fora do projeto
*External Libraries/ // bibliotecas baixadas de dependencias