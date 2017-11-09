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
	   receita para criar novas instancias da classe da classe definida pela definição da Bean
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


// código
java.util.logging.Logger // mostra dados na tela


// principal
aplicacao/ // camada da aplicacao
	build/ // arquivos class da compilacao
	build.gradle // arquivo de configs de compilacao e outros
	src/
		test/ // arquivos de teste da main/
		main/
			resources/ // arquivos do banco de dados e controle de versao do flyway
			groovy/
				aplicacao/
				

				config/
					audithook/
						HibernateConfiguration.groovy // A JPA define um meio de mapeamento objeto-relacional para objetos Java simples e comuns (POJOs), 
													  // denominados beans de entidade
													  // é um HibernateJpaAutoConfiguration
													  // usa hibernate.ejb.interceptor
						// @Autowired
						// @Override
						PkgsOracleInterceptor.groovy
						// @Component
						// @Autowired
    					// @Lazy
    					// @Override
    					// @SuppressWarnings


					undertow/


				

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