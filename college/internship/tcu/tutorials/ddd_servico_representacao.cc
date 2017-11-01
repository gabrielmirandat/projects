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
// PAREI AQUI
@RestController
@Autowired
@Value
@PostMapping
@RequestBody
@RequestParam
@PathVariable

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
				infra/
				rest/
					AutenticacaoRest.groovy // faz autenticação de usuário
					// @RestController
					// @Autowired
					// @Value
					// @PostMapping
					// @RequestBody
					AutuarRepresentacaoRest.groovy // entender depois
					// @RestController
					// @GetMapping
					// @RequestParam
					// @PathVariable
					// @PostMapping
					// @RequestBody
					ControladorExcecao.groovy
					CriaContratoRest.groovy
					CriarLicitacaoRest.groovy
					DocumentoRest.groovy
					PessoaQualificadaRest.groovy
					ProcessoRest.groovy
					RepresentacaoRest.groovy
				sanityrest/
					Http2ServiceRest.groovy  // controlador REST / mapeia "/", "/entity-flow", "/push"
					// @RestController
					// @GetMapping
				RepresentacaoMain.groovy // roda aplicacao SpringBoot / cria um Bean
				// @SpringBootApplication
				// @EnableFeignClients
				// @Bean





dominio/ // camada de dominios
	build/ // arquivos class da compilacao
	src/
	build.gradle // arquivo de configs de compilacao


// outros
gradle/ // arq de propriedades do GRADLE WRAPPER
k8s/ // arq de config de deploy e outros do RANCHER
representacao/ // arq de propriedades do SISTEMA REPRESENTACAO

// fora do projeto
External Libraries/ // bibliotecas baixadas de dependencias