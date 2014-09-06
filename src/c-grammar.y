%{
#define YYSTYPE ScmObj
static ScmObj token_table = SCM_UNBOUND;
static ScmObj name_348 = SCM_UNBOUND;
static ScmObj name_346 = SCM_UNBOUND;
static ScmObj name_341 = SCM_UNBOUND;
static ScmObj name_340 = SCM_UNBOUND;
static ScmObj name_339 = SCM_UNBOUND;
static ScmObj name_337 = SCM_UNBOUND;
static ScmObj name_335 = SCM_UNBOUND;
static ScmObj name_331 = SCM_UNBOUND;
static ScmObj name_329 = SCM_UNBOUND;
static ScmObj name_324 = SCM_UNBOUND;
static ScmObj name_321 = SCM_UNBOUND;
static ScmObj name_313 = SCM_UNBOUND;
static ScmObj name_311 = SCM_UNBOUND;
static ScmObj name_306 = SCM_UNBOUND;
static ScmObj name_304 = SCM_UNBOUND;
static ScmObj name_302 = SCM_UNBOUND;
static ScmObj name_301 = SCM_UNBOUND;
static ScmObj name_288 = SCM_UNBOUND;
static ScmObj name_286 = SCM_UNBOUND;
static ScmObj name_284 = SCM_UNBOUND;
static ScmObj name_274 = SCM_UNBOUND;
static ScmObj name_272 = SCM_UNBOUND;
static ScmObj name_270 = SCM_UNBOUND;
static ScmObj name_257 = SCM_UNBOUND;
static ScmObj name_253 = SCM_UNBOUND;
static ScmObj name_196 = SCM_UNBOUND;
static ScmObj name_188 = SCM_UNBOUND;
static ScmObj name_179 = SCM_UNBOUND;
static ScmObj name_178 = SCM_UNBOUND;
static ScmObj name_175 = SCM_UNBOUND;
static ScmObj name_167 = SCM_UNBOUND;
static ScmObj name_164 = SCM_UNBOUND;
static ScmObj name_151 = SCM_UNBOUND;
static ScmObj name_148 = SCM_UNBOUND;
static ScmObj name_145 = SCM_UNBOUND;
static ScmObj name_142 = SCM_UNBOUND;
static ScmObj name_139 = SCM_UNBOUND;
static ScmObj name_136 = SCM_UNBOUND;
static ScmObj name_133 = SCM_UNBOUND;
static ScmObj name_130 = SCM_UNBOUND;
static ScmObj name_128 = SCM_UNBOUND;
static ScmObj name_125 = SCM_UNBOUND;
static ScmObj name_123 = SCM_UNBOUND;
static ScmObj name_121 = SCM_UNBOUND;
static ScmObj name_119 = SCM_UNBOUND;
static ScmObj name_116 = SCM_UNBOUND;
static ScmObj name_114 = SCM_UNBOUND;
static ScmObj name_111 = SCM_UNBOUND;
static ScmObj name_109 = SCM_UNBOUND;
static ScmObj name_106 = SCM_UNBOUND;
static ScmObj name_104 = SCM_UNBOUND;
static ScmObj name_102 = SCM_UNBOUND;
static ScmObj name_99 = SCM_UNBOUND;
static ScmObj name_89 = SCM_UNBOUND;
static ScmObj name_87 = SCM_UNBOUND;
static ScmObj name_85 = SCM_UNBOUND;
static ScmObj name_83 = SCM_UNBOUND;
static ScmObj name_81 = SCM_UNBOUND;
static ScmObj name_76 = SCM_UNBOUND;
static ScmObj name_74 = SCM_UNBOUND;
static ScmObj name_72 = SCM_UNBOUND;
static ScmObj name_70 = SCM_UNBOUND;
static ScmObj name_67 = SCM_UNBOUND;
static ScmObj name_65 = SCM_UNBOUND;
static ScmObj name_57 = SCM_UNBOUND;
static ScmObj name_55 = SCM_UNBOUND;
static ScmObj name_53 = SCM_UNBOUND;
static ScmObj name_49 = SCM_UNBOUND;
static ScmObj name_47 = SCM_UNBOUND;
static ScmObj name_43 = SCM_UNBOUND;
static ScmObj name_41 = SCM_UNBOUND;
static ScmObj name_36 = SCM_UNBOUND;
static ScmObj name_34 = SCM_UNBOUND;
static ScmObj name_27 = SCM_UNBOUND;
static ScmObj name_16 = SCM_UNBOUND;
static ScmObj name_11 = SCM_UNBOUND;
static ScmObj name_8 = SCM_UNBOUND;
static ScmObj name_1 = SCM_UNBOUND;
static ScmObj token_sym_START_MACRO = SCM_UNBOUND;
static ScmObj token_sym_OBJC_STRING = SCM_UNBOUND;
static ScmObj token_sym_AT_REQUIRED = SCM_UNBOUND;
static ScmObj token_sym_AT_OPTIONAL = SCM_UNBOUND;
static ScmObj token_sym_AT_DYNAMIC = SCM_UNBOUND;
static ScmObj token_sym_AT_SYNTHESIZE = SCM_UNBOUND;
static ScmObj token_sym_AT_PROPERTY = SCM_UNBOUND;
static ScmObj token_sym_AT_SYNCHRONIZED = SCM_UNBOUND;
static ScmObj token_sym_AT_FINALLY = SCM_UNBOUND;
static ScmObj token_sym_AT_CATCH = SCM_UNBOUND;
static ScmObj token_sym_AT_TRY = SCM_UNBOUND;
static ScmObj token_sym_AT_THROW = SCM_UNBOUND;
static ScmObj token_sym_AT_ALIAS = SCM_UNBOUND;
static ScmObj token_sym_AT_CLASS = SCM_UNBOUND;
static ScmObj token_sym_AT_PROTOCOL = SCM_UNBOUND;
static ScmObj token_sym_AT_PACKAGE = SCM_UNBOUND;
static ScmObj token_sym_AT_PROTECTED = SCM_UNBOUND;
static ScmObj token_sym_AT_PRIVATE = SCM_UNBOUND;
static ScmObj token_sym_AT_PUBLIC = SCM_UNBOUND;
static ScmObj token_sym_AT_ENCODE = SCM_UNBOUND;
static ScmObj token_sym_AT_DEFS = SCM_UNBOUND;
static ScmObj token_sym_AT_SELECTOR = SCM_UNBOUND;
static ScmObj token_sym_AT_END = SCM_UNBOUND;
static ScmObj token_sym_AT_IMPLEMENTATION = SCM_UNBOUND;
static ScmObj token_sym_AT_INTERFACE = SCM_UNBOUND;
static ScmObj token_sym_EXTENSION = SCM_UNBOUND;
static ScmObj token_sym_UNKNOWN = SCM_UNBOUND;
static ScmObj token_sym_ASM = SCM_UNBOUND;
static ScmObj token_sym_RETURN = SCM_UNBOUND;
static ScmObj token_sym_BREAK = SCM_UNBOUND;
static ScmObj token_sym_CONTINUE = SCM_UNBOUND;
static ScmObj token_sym_GOTO = SCM_UNBOUND;
static ScmObj token_sym_FOR = SCM_UNBOUND;
static ScmObj token_sym_DO = SCM_UNBOUND;
static ScmObj token_sym_WHILE = SCM_UNBOUND;
static ScmObj token_sym_SWITCH = SCM_UNBOUND;
static ScmObj token_sym_ELSE = SCM_UNBOUND;
static ScmObj token_sym_IF = SCM_UNBOUND;
static ScmObj token_sym_DEFAULT = SCM_UNBOUND;
static ScmObj token_sym_CASE = SCM_UNBOUND;
static ScmObj token_sym_RANGE = SCM_UNBOUND;
static ScmObj token_sym_ELLIPSIS = SCM_UNBOUND;
static ScmObj token_sym_ENUM = SCM_UNBOUND;
static ScmObj token_sym_UNION = SCM_UNBOUND;
static ScmObj token_sym_STRUCT = SCM_UNBOUND;
static ScmObj token_sym_VOLATILE = SCM_UNBOUND;
static ScmObj token_sym_CONST = SCM_UNBOUND;
static ScmObj token_sym_UNSIGNED = SCM_UNBOUND;
static ScmObj token_sym_SIGNED = SCM_UNBOUND;
static ScmObj token_sym_RESTRICT = SCM_UNBOUND;
static ScmObj token_sym_INLINE = SCM_UNBOUND;
static ScmObj token_sym_REGISTER = SCM_UNBOUND;
static ScmObj token_sym_AUTO = SCM_UNBOUND;
static ScmObj token_sym_STATIC = SCM_UNBOUND;
static ScmObj token_sym_EXTERN = SCM_UNBOUND;
static ScmObj token_sym_TYPEDEF = SCM_UNBOUND;
static ScmObj token_sym_TYPENAME = SCM_UNBOUND;
static ScmObj token_sym_OR_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_XOR_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_AND_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_RIGHT_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_LEFT_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_SUB_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_ADD_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_MOD_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_DIV_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_MUL_ASSIGN = SCM_UNBOUND;
static ScmObj token_sym_OR_OP = SCM_UNBOUND;
static ScmObj token_sym_AND_OP = SCM_UNBOUND;
static ScmObj token_sym_NE_OP = SCM_UNBOUND;
static ScmObj token_sym_EQ_OP = SCM_UNBOUND;
static ScmObj token_sym_GE_OP = SCM_UNBOUND;
static ScmObj token_sym_LE_OP = SCM_UNBOUND;
static ScmObj token_sym_RIGHT_OP = SCM_UNBOUND;
static ScmObj token_sym_LEFT_OP = SCM_UNBOUND;
static ScmObj token_sym_DEC_OP = SCM_UNBOUND;
static ScmObj token_sym_INC_OP = SCM_UNBOUND;
static ScmObj token_sym_PTR_OP = SCM_UNBOUND;
static ScmObj token_sym_SIZEOF = SCM_UNBOUND;
static ScmObj token_sym_STRING = SCM_UNBOUND;
static ScmObj token_sym_CONSTANT = SCM_UNBOUND;
static ScmObj token_sym_IDENTIFIER = SCM_UNBOUND;
static ScmObj token_sym__GT = SCM_UNBOUND;
static ScmObj token_sym__LT = SCM_UNBOUND;
static ScmObj token_sym_P = SCM_UNBOUND;
static ScmObj token_sym__3d = SCM_UNBOUND;
static ScmObj token_sym__25 = SCM_UNBOUND;
static ScmObj token_sym__26 = SCM_UNBOUND;
static ScmObj token_sym__5e = SCM_UNBOUND;
static ScmObj token_sym__2f = SCM_UNBOUND;
static ScmObj token_sym__2a = SCM_UNBOUND;
static ScmObj token_sym__ = SCM_UNBOUND;
static ScmObj token_sym__2b = SCM_UNBOUND;
static ScmObj token_sym_X = SCM_UNBOUND;
static ScmObj token_sym__7e = SCM_UNBOUND;
static ScmObj token_sym_COLON = SCM_UNBOUND;
static ScmObj token_sym_DOT = SCM_UNBOUND;
static ScmObj token_sym_OR = SCM_UNBOUND;
static ScmObj token_sym_RPAREN = SCM_UNBOUND;
static ScmObj token_sym_LPAREN = SCM_UNBOUND;
static ScmObj token_sym_RSBRA = SCM_UNBOUND;
static ScmObj token_sym_LSBRA = SCM_UNBOUND;
static ScmObj token_sym_RCBRA = SCM_UNBOUND;
static ScmObj token_sym_LCBRA = SCM_UNBOUND;
static ScmObj token_sym_COMMA = SCM_UNBOUND;
static ScmObj token_sym_SEMICOLON = SCM_UNBOUND;
#ifdef USE_PROFILER
static long long _profile_name_39_count = 0;
static long long _profile_name_39_time = 0;
static long long _profile_yylex_count = 0;
static long long _profile_yylex_time = 0;
static long long _profile_name_250_count = 0;
static long long _profile_name_250_time = 0;
static long long _profile_name_251_count = 0;
static long long _profile_name_251_time = 0;
static long long _profile_name_252_count = 0;
static long long _profile_name_252_time = 0;
static long long _profile_name_131_count = 0;
static long long _profile_name_131_time = 0;
static long long _profile_name_132_count = 0;
static long long _profile_name_132_time = 0;
static long long _profile_name_254_count = 0;
static long long _profile_name_254_time = 0;
static long long _profile_name_255_count = 0;
static long long _profile_name_255_time = 0;
static long long _profile_name_134_count = 0;
static long long _profile_name_134_time = 0;
static long long _profile_name_256_count = 0;
static long long _profile_name_256_time = 0;
static long long _profile_name_135_count = 0;
static long long _profile_name_135_time = 0;
static long long _profile_name_258_count = 0;
static long long _profile_name_258_time = 0;
static long long _profile_name_137_count = 0;
static long long _profile_name_137_time = 0;
static long long _profile_name_259_count = 0;
static long long _profile_name_259_time = 0;
static long long _profile_name_138_count = 0;
static long long _profile_name_138_time = 0;
static long long _profile_name_40_count = 0;
static long long _profile_name_40_time = 0;
static long long _profile_name_42_count = 0;
static long long _profile_name_42_time = 0;
static long long _profile_name_44_count = 0;
static long long _profile_name_44_time = 0;
static long long _profile_name_45_count = 0;
static long long _profile_name_45_time = 0;
static long long _profile_name_46_count = 0;
static long long _profile_name_46_time = 0;
static long long _profile_name_48_count = 0;
static long long _profile_name_48_time = 0;
static long long _profile_name_260_count = 0;
static long long _profile_name_260_time = 0;
static long long _profile_name_261_count = 0;
static long long _profile_name_261_time = 0;
static long long _profile_name_140_count = 0;
static long long _profile_name_140_time = 0;
static long long _profile_name_262_count = 0;
static long long _profile_name_262_time = 0;
static long long _profile_name_141_count = 0;
static long long _profile_name_141_time = 0;
static long long _profile_name_263_count = 0;
static long long _profile_name_263_time = 0;
static long long _profile_name_264_count = 0;
static long long _profile_name_264_time = 0;
static long long _profile_name_143_count = 0;
static long long _profile_name_143_time = 0;
static long long _profile_name_265_count = 0;
static long long _profile_name_265_time = 0;
static long long _profile_name_144_count = 0;
static long long _profile_name_144_time = 0;
static long long _profile_name_266_count = 0;
static long long _profile_name_266_time = 0;
static long long _profile_name_300_count = 0;
static long long _profile_name_300_time = 0;
static long long _profile_name_267_count = 0;
static long long _profile_name_267_time = 0;
static long long _profile_name_146_count = 0;
static long long _profile_name_146_time = 0;
static long long _profile_name_268_count = 0;
static long long _profile_name_268_time = 0;
static long long _profile_name_147_count = 0;
static long long _profile_name_147_time = 0;
static long long _profile_name_269_count = 0;
static long long _profile_name_269_time = 0;
static long long _profile_name_303_count = 0;
static long long _profile_name_303_time = 0;
static long long _profile_name_149_count = 0;
static long long _profile_name_149_time = 0;
static long long _profile_name_305_count = 0;
static long long _profile_name_305_time = 0;
static long long _profile_name_307_count = 0;
static long long _profile_name_307_time = 0;
static long long _profile_name_308_count = 0;
static long long _profile_name_308_time = 0;
static long long _profile_name_309_count = 0;
static long long _profile_name_309_time = 0;
static long long _profile_name_50_count = 0;
static long long _profile_name_50_time = 0;
static long long _profile_name_51_count = 0;
static long long _profile_name_51_time = 0;
static long long _profile_name_52_count = 0;
static long long _profile_name_52_time = 0;
static long long _profile_name_54_count = 0;
static long long _profile_name_54_time = 0;
static long long _profile_name_56_count = 0;
static long long _profile_name_56_time = 0;
static long long _profile_name_58_count = 0;
static long long _profile_name_58_time = 0;
static long long _profile_name_59_count = 0;
static long long _profile_name_59_time = 0;
static long long _profile_name_2_count = 0;
static long long _profile_name_2_time = 0;
static long long _profile_name_3_count = 0;
static long long _profile_name_3_time = 0;
static long long _profile_name_4_count = 0;
static long long _profile_name_4_time = 0;
static long long _profile_name_5_count = 0;
static long long _profile_name_5_time = 0;
static long long _profile_name_6_count = 0;
static long long _profile_name_6_time = 0;
static long long _profile_name_7_count = 0;
static long long _profile_name_7_time = 0;
static long long _profile_name_271_count = 0;
static long long _profile_name_271_time = 0;
static long long _profile_name_150_count = 0;
static long long _profile_name_150_time = 0;
static long long _profile_name_9_count = 0;
static long long _profile_name_9_time = 0;
static long long _profile_name_273_count = 0;
static long long _profile_name_273_time = 0;
static long long _profile_name_152_count = 0;
static long long _profile_name_152_time = 0;
static long long _profile_name_153_count = 0;
static long long _profile_name_153_time = 0;
static long long _profile_name_275_count = 0;
static long long _profile_name_275_time = 0;
static long long _profile_name_154_count = 0;
static long long _profile_name_154_time = 0;
static long long _profile_name_276_count = 0;
static long long _profile_name_276_time = 0;
static long long _profile_name_155_count = 0;
static long long _profile_name_155_time = 0;
static long long _profile_name_310_count = 0;
static long long _profile_name_310_time = 0;
static long long _profile_name_277_count = 0;
static long long _profile_name_277_time = 0;
static long long _profile_name_156_count = 0;
static long long _profile_name_156_time = 0;
static long long _profile_name_278_count = 0;
static long long _profile_name_278_time = 0;
static long long _profile_name_157_count = 0;
static long long _profile_name_157_time = 0;
static long long _profile_name_312_count = 0;
static long long _profile_name_312_time = 0;
static long long _profile_name_279_count = 0;
static long long _profile_name_279_time = 0;
static long long _profile_name_158_count = 0;
static long long _profile_name_158_time = 0;
static long long _profile_name_159_count = 0;
static long long _profile_name_159_time = 0;
static long long _profile_name_314_count = 0;
static long long _profile_name_314_time = 0;
static long long _profile_name_315_count = 0;
static long long _profile_name_315_time = 0;
static long long _profile_name_316_count = 0;
static long long _profile_name_316_time = 0;
static long long _profile_name_317_count = 0;
static long long _profile_name_317_time = 0;
static long long _profile_name_318_count = 0;
static long long _profile_name_318_time = 0;
static long long _profile_name_319_count = 0;
static long long _profile_name_319_time = 0;
static long long _profile_name_60_count = 0;
static long long _profile_name_60_time = 0;
static long long _profile_name_61_count = 0;
static long long _profile_name_61_time = 0;
static long long _profile_name_62_count = 0;
static long long _profile_name_62_time = 0;
static long long _profile_name_63_count = 0;
static long long _profile_name_63_time = 0;
static long long _profile_name_64_count = 0;
static long long _profile_name_64_time = 0;
static long long _profile_name_66_count = 0;
static long long _profile_name_66_time = 0;
static long long _profile_name_68_count = 0;
static long long _profile_name_68_time = 0;
static long long _profile_name_69_count = 0;
static long long _profile_name_69_time = 0;
static long long _profile_name_280_count = 0;
static long long _profile_name_280_time = 0;
static long long _profile_name_281_count = 0;
static long long _profile_name_281_time = 0;
static long long _profile_name_160_count = 0;
static long long _profile_name_160_time = 0;
static long long _profile_name_282_count = 0;
static long long _profile_name_282_time = 0;
static long long _profile_name_161_count = 0;
static long long _profile_name_161_time = 0;
static long long _profile_name_283_count = 0;
static long long _profile_name_283_time = 0;
static long long _profile_name_162_count = 0;
static long long _profile_name_162_time = 0;
static long long _profile_name_163_count = 0;
static long long _profile_name_163_time = 0;
static long long _profile_name_285_count = 0;
static long long _profile_name_285_time = 0;
static long long _profile_name_165_count = 0;
static long long _profile_name_165_time = 0;
static long long _profile_name_320_count = 0;
static long long _profile_name_320_time = 0;
static long long _profile_name_287_count = 0;
static long long _profile_name_287_time = 0;
static long long _profile_name_166_count = 0;
static long long _profile_name_166_time = 0;
static long long _profile_name_200_count = 0;
static long long _profile_name_200_time = 0;
static long long _profile_name_322_count = 0;
static long long _profile_name_322_time = 0;
static long long _profile_name_289_count = 0;
static long long _profile_name_289_time = 0;
static long long _profile_name_168_count = 0;
static long long _profile_name_168_time = 0;
static long long _profile_name_201_count = 0;
static long long _profile_name_201_time = 0;
static long long _profile_name_323_count = 0;
static long long _profile_name_323_time = 0;
static long long _profile_name_169_count = 0;
static long long _profile_name_169_time = 0;
static long long _profile_name_202_count = 0;
static long long _profile_name_202_time = 0;
static long long _profile_name_203_count = 0;
static long long _profile_name_203_time = 0;
static long long _profile_name_325_count = 0;
static long long _profile_name_325_time = 0;
static long long _profile_name_204_count = 0;
static long long _profile_name_204_time = 0;
static long long _profile_name_326_count = 0;
static long long _profile_name_326_time = 0;
static long long _profile_name_205_count = 0;
static long long _profile_name_205_time = 0;
static long long _profile_name_327_count = 0;
static long long _profile_name_327_time = 0;
static long long _profile_name_206_count = 0;
static long long _profile_name_206_time = 0;
static long long _profile_name_328_count = 0;
static long long _profile_name_328_time = 0;
static long long _profile_name_207_count = 0;
static long long _profile_name_207_time = 0;
static long long _profile_name_208_count = 0;
static long long _profile_name_208_time = 0;
static long long _profile_name_71_count = 0;
static long long _profile_name_71_time = 0;
static long long _profile_name_209_count = 0;
static long long _profile_name_209_time = 0;
static long long _profile_name_73_count = 0;
static long long _profile_name_73_time = 0;
static long long _profile_name_75_count = 0;
static long long _profile_name_75_time = 0;
static long long _profile_name_77_count = 0;
static long long _profile_name_77_time = 0;
static long long _profile_name_78_count = 0;
static long long _profile_name_78_time = 0;
static long long _profile_name_79_count = 0;
static long long _profile_name_79_time = 0;
static long long _profile_name_290_count = 0;
static long long _profile_name_290_time = 0;
static long long _profile_name_291_count = 0;
static long long _profile_name_291_time = 0;
static long long _profile_name_170_count = 0;
static long long _profile_name_170_time = 0;
static long long _profile_name_292_count = 0;
static long long _profile_name_292_time = 0;
static long long _profile_name_171_count = 0;
static long long _profile_name_171_time = 0;
static long long _profile_name_293_count = 0;
static long long _profile_name_293_time = 0;
static long long _profile_name_172_count = 0;
static long long _profile_name_172_time = 0;
static long long _profile_name_294_count = 0;
static long long _profile_name_294_time = 0;
static long long _profile_name_173_count = 0;
static long long _profile_name_173_time = 0;
static long long _profile_name_295_count = 0;
static long long _profile_name_295_time = 0;
static long long _profile_name_174_count = 0;
static long long _profile_name_174_time = 0;
static long long _profile_c_scan_count = 0;
static long long _profile_c_scan_time = 0;
static long long _profile_name_296_count = 0;
static long long _profile_name_296_time = 0;
static long long _profile_name_330_count = 0;
static long long _profile_name_330_time = 0;
static long long _profile_name_297_count = 0;
static long long _profile_name_297_time = 0;
static long long _profile_name_176_count = 0;
static long long _profile_name_176_time = 0;
static long long _profile_name_298_count = 0;
static long long _profile_name_298_time = 0;
static long long _profile_name_177_count = 0;
static long long _profile_name_177_time = 0;
static long long _profile_name_210_count = 0;
static long long _profile_name_210_time = 0;
static long long _profile_name_332_count = 0;
static long long _profile_name_332_time = 0;
static long long _profile_name_299_count = 0;
static long long _profile_name_299_time = 0;
static long long _profile_name_211_count = 0;
static long long _profile_name_211_time = 0;
static long long _profile_name_333_count = 0;
static long long _profile_name_333_time = 0;
static long long _profile_name_212_count = 0;
static long long _profile_name_212_time = 0;
static long long _profile_name_334_count = 0;
static long long _profile_name_334_time = 0;
static long long _profile_name_213_count = 0;
static long long _profile_name_213_time = 0;
static long long _profile_name_214_count = 0;
static long long _profile_name_214_time = 0;
static long long _profile_name_336_count = 0;
static long long _profile_name_336_time = 0;
static long long _profile_name_215_count = 0;
static long long _profile_name_215_time = 0;
static long long _profile_name_216_count = 0;
static long long _profile_name_216_time = 0;
static long long _profile_name_338_count = 0;
static long long _profile_name_338_time = 0;
static long long _profile_name_217_count = 0;
static long long _profile_name_217_time = 0;
static long long _profile_name_80_count = 0;
static long long _profile_name_80_time = 0;
static long long _profile_name_218_count = 0;
static long long _profile_name_218_time = 0;
static long long _profile_name_219_count = 0;
static long long _profile_name_219_time = 0;
static long long _profile_name_82_count = 0;
static long long _profile_name_82_time = 0;
static long long _profile_name_84_count = 0;
static long long _profile_name_84_time = 0;
static long long _profile_name_86_count = 0;
static long long _profile_name_86_time = 0;
static long long _profile_name_88_count = 0;
static long long _profile_name_88_time = 0;
static long long _profile_name_180_count = 0;
static long long _profile_name_180_time = 0;
static long long _profile_name_181_count = 0;
static long long _profile_name_181_time = 0;
static long long _profile_name_182_count = 0;
static long long _profile_name_182_time = 0;
static long long _profile_name_183_count = 0;
static long long _profile_name_183_time = 0;
static long long _profile_name_184_count = 0;
static long long _profile_name_184_time = 0;
static long long _profile_name_185_count = 0;
static long long _profile_name_185_time = 0;
static long long _profile_name_186_count = 0;
static long long _profile_name_186_time = 0;
static long long _profile_name_187_count = 0;
static long long _profile_name_187_time = 0;
static long long _profile_name_220_count = 0;
static long long _profile_name_220_time = 0;
static long long _profile_name_342_count = 0;
static long long _profile_name_342_time = 0;
static long long _profile_name_100_count = 0;
static long long _profile_name_100_time = 0;
static long long _profile_name_221_count = 0;
static long long _profile_name_221_time = 0;
static long long _profile_name_343_count = 0;
static long long _profile_name_343_time = 0;
static long long _profile_name_101_count = 0;
static long long _profile_name_101_time = 0;
static long long _profile_name_189_count = 0;
static long long _profile_name_189_time = 0;
static long long _profile_name_222_count = 0;
static long long _profile_name_222_time = 0;
static long long _profile_name_344_count = 0;
static long long _profile_name_344_time = 0;
static long long _profile_name_223_count = 0;
static long long _profile_name_223_time = 0;
static long long _profile_name_345_count = 0;
static long long _profile_name_345_time = 0;
static long long _profile_name_103_count = 0;
static long long _profile_name_103_time = 0;
static long long _profile_name_224_count = 0;
static long long _profile_name_224_time = 0;
static long long _profile_name_225_count = 0;
static long long _profile_name_225_time = 0;
static long long _profile_name_347_count = 0;
static long long _profile_name_347_time = 0;
static long long _profile_name_105_count = 0;
static long long _profile_name_105_time = 0;
static long long _profile_name_226_count = 0;
static long long _profile_name_226_time = 0;
static long long _profile_name_227_count = 0;
static long long _profile_name_227_time = 0;
static long long _profile_name_349_count = 0;
static long long _profile_name_349_time = 0;
static long long _profile_name_90_count = 0;
static long long _profile_name_90_time = 0;
static long long _profile_name_107_count = 0;
static long long _profile_name_107_time = 0;
static long long _profile_name_228_count = 0;
static long long _profile_name_228_time = 0;
static long long _profile_name_91_count = 0;
static long long _profile_name_91_time = 0;
static long long _profile_name_108_count = 0;
static long long _profile_name_108_time = 0;
static long long _profile_name_229_count = 0;
static long long _profile_name_229_time = 0;
static long long _profile_name_92_count = 0;
static long long _profile_name_92_time = 0;
static long long _profile_name_93_count = 0;
static long long _profile_name_93_time = 0;
static long long _profile_name_94_count = 0;
static long long _profile_name_94_time = 0;
static long long _profile_name_95_count = 0;
static long long _profile_name_95_time = 0;
static long long _profile_name_96_count = 0;
static long long _profile_name_96_time = 0;
static long long _profile_name_97_count = 0;
static long long _profile_name_97_time = 0;
static long long _profile_name_10_count = 0;
static long long _profile_name_10_time = 0;
static long long _profile_name_98_count = 0;
static long long _profile_name_98_time = 0;
static long long _profile_name_12_count = 0;
static long long _profile_name_12_time = 0;
static long long _profile_name_13_count = 0;
static long long _profile_name_13_time = 0;
static long long _profile_name_14_count = 0;
static long long _profile_name_14_time = 0;
static long long _profile_name_15_count = 0;
static long long _profile_name_15_time = 0;
static long long _profile_name_17_count = 0;
static long long _profile_name_17_time = 0;
static long long _profile_name_18_count = 0;
static long long _profile_name_18_time = 0;
static long long _profile_name_190_count = 0;
static long long _profile_name_190_time = 0;
static long long _profile_name_19_count = 0;
static long long _profile_name_19_time = 0;
static long long _profile_name_191_count = 0;
static long long _profile_name_191_time = 0;
static long long _profile_name_192_count = 0;
static long long _profile_name_192_time = 0;
static long long _profile_name_193_count = 0;
static long long _profile_name_193_time = 0;
static long long _profile_name_194_count = 0;
static long long _profile_name_194_time = 0;
static long long _profile_name_195_count = 0;
static long long _profile_name_195_time = 0;
static long long _profile_name_197_count = 0;
static long long _profile_name_197_time = 0;
static long long _profile_name_230_count = 0;
static long long _profile_name_230_time = 0;
static long long _profile_name_110_count = 0;
static long long _profile_name_110_time = 0;
static long long _profile_name_198_count = 0;
static long long _profile_name_198_time = 0;
static long long _profile_name_231_count = 0;
static long long _profile_name_231_time = 0;
static long long _profile_name_199_count = 0;
static long long _profile_name_199_time = 0;
static long long _profile_name_232_count = 0;
static long long _profile_name_232_time = 0;
static long long _profile_name_112_count = 0;
static long long _profile_name_112_time = 0;
static long long _profile_name_233_count = 0;
static long long _profile_name_233_time = 0;
static long long _profile_name_113_count = 0;
static long long _profile_name_113_time = 0;
static long long _profile_name_234_count = 0;
static long long _profile_name_234_time = 0;
static long long _profile_name_235_count = 0;
static long long _profile_name_235_time = 0;
static long long _profile_name_115_count = 0;
static long long _profile_name_115_time = 0;
static long long _profile_name_236_count = 0;
static long long _profile_name_236_time = 0;
static long long _profile_name_237_count = 0;
static long long _profile_name_237_time = 0;
static long long _profile_name_117_count = 0;
static long long _profile_name_117_time = 0;
static long long _profile_name_238_count = 0;
static long long _profile_name_238_time = 0;
static long long _profile_name_118_count = 0;
static long long _profile_name_118_time = 0;
static long long _profile_name_239_count = 0;
static long long _profile_name_239_time = 0;
static long long _profile_name_20_count = 0;
static long long _profile_name_20_time = 0;
static long long _profile_name_21_count = 0;
static long long _profile_name_21_time = 0;
static long long _profile_name_22_count = 0;
static long long _profile_name_22_time = 0;
static long long _profile_name_23_count = 0;
static long long _profile_name_23_time = 0;
static long long _profile_name_24_count = 0;
static long long _profile_name_24_time = 0;
static long long _profile_name_25_count = 0;
static long long _profile_name_25_time = 0;
static long long _profile_name_26_count = 0;
static long long _profile_name_26_time = 0;
static long long _profile_name_28_count = 0;
static long long _profile_name_28_time = 0;
static long long _profile_name_29_count = 0;
static long long _profile_name_29_time = 0;
static long long _profile_name_240_count = 0;
static long long _profile_name_240_time = 0;
static long long _profile_name_120_count = 0;
static long long _profile_name_120_time = 0;
static long long _profile_name_241_count = 0;
static long long _profile_name_241_time = 0;
static long long _profile_name_242_count = 0;
static long long _profile_name_242_time = 0;
static long long _profile_name_122_count = 0;
static long long _profile_name_122_time = 0;
static long long _profile_name_243_count = 0;
static long long _profile_name_243_time = 0;
static long long _profile_name_244_count = 0;
static long long _profile_name_244_time = 0;
static long long _profile_name_245_count = 0;
static long long _profile_name_245_time = 0;
static long long _profile_name_124_count = 0;
static long long _profile_name_124_time = 0;
static long long _profile_name_246_count = 0;
static long long _profile_name_246_time = 0;
static long long _profile_name_247_count = 0;
static long long _profile_name_247_time = 0;
static long long _profile_name_126_count = 0;
static long long _profile_name_126_time = 0;
static long long _profile_name_248_count = 0;
static long long _profile_name_248_time = 0;
static long long _profile_name_127_count = 0;
static long long _profile_name_127_time = 0;
static long long _profile_name_249_count = 0;
static long long _profile_name_249_time = 0;
static long long _profile_name_129_count = 0;
static long long _profile_name_129_time = 0;
static long long _profile_name_30_count = 0;
static long long _profile_name_30_time = 0;
static long long _profile_name_31_count = 0;
static long long _profile_name_31_time = 0;
static long long _profile_name_32_count = 0;
static long long _profile_name_32_time = 0;
static long long _profile_name_33_count = 0;
static long long _profile_name_33_time = 0;
static long long _profile_name_35_count = 0;
static long long _profile_name_35_time = 0;
static long long _profile_name_37_count = 0;
static long long _profile_name_37_time = 0;
static long long _profile_name_38_count = 0;
static long long _profile_name_38_time = 0;
#endif
%}
%token SEMICOLON
%token COMMA
%token LCBRA
%token RCBRA
%token LSBRA
%token RSBRA
%token LPAREN
%token RPAREN
%token OR
%token DOT
%token COLON
%token _7e
%token X
%token _2b
%token _
%token _2a
%token _2f
%token _5e
%token _26
%token _25
%token _3d
%token P
%token _LT
%token _GT
%token IDENTIFIER
%token CONSTANT
%token STRING
%token SIZEOF
%token PTR_OP
%token INC_OP
%token DEC_OP
%token LEFT_OP
%token RIGHT_OP
%token LE_OP
%token GE_OP
%token EQ_OP
%token NE_OP
%token AND_OP
%token OR_OP
%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token ADD_ASSIGN
%token SUB_ASSIGN
%token LEFT_ASSIGN
%token RIGHT_ASSIGN
%token AND_ASSIGN
%token XOR_ASSIGN
%token OR_ASSIGN
%token TYPENAME
%token TYPEDEF
%token EXTERN
%token STATIC
%token AUTO
%token REGISTER
%token INLINE
%token RESTRICT
%token SIGNED
%token UNSIGNED
%token CONST
%token VOLATILE
%token STRUCT
%token UNION
%token ENUM
%token ELLIPSIS
%token RANGE
%token CASE
%token DEFAULT
%token IF
%token ELSE
%token SWITCH
%token WHILE
%token DO
%token FOR
%token GOTO
%token CONTINUE
%token BREAK
%token RETURN
%token ASM
%token UNKNOWN
%token EXTENSION
%token AT_INTERFACE
%token AT_IMPLEMENTATION
%token AT_END
%token AT_SELECTOR
%token AT_DEFS
%token AT_ENCODE
%token AT_PUBLIC
%token AT_PRIVATE
%token AT_PROTECTED
%token AT_PACKAGE
%token AT_PROTOCOL
%token AT_CLASS
%token AT_ALIAS
%token AT_THROW
%token AT_TRY
%token AT_CATCH
%token AT_FINALLY
%token AT_SYNCHRONIZED
%token AT_PROPERTY
%token AT_SYNTHESIZE
%token AT_DYNAMIC
%token AT_OPTIONAL
%token AT_REQUIRED
%token OBJC_STRING
%token START_MACRO
%%
program
	:  
	| file 
	| START_MACRO statement_list { START_PROFILE(name_2) $$ = Scm_ApplyRec1(name_1, $2); END_PROFILE(name_2) }
;

file
	: external_definition 
	| file external_definition 
;

external_definition
	: maybe_extension function_definition { START_PROFILE(name_3) $$ = Scm_AllReferencedInfoClear(); END_PROFILE(name_3) }
	| maybe_extension asm_definition { START_PROFILE(name_4) $$ = Scm_AllReferencedInfoClear(); END_PROFILE(name_4) }
	| maybe_extension external_declaration { START_PROFILE(name_5) $$ = Scm_AllReferencedInfoClear(); END_PROFILE(name_5) }
	| objc_definition { START_PROFILE(name_6) $$ = Scm_AllReferencedInfoClear(); END_PROFILE(name_6) }
	| SEMICOLON { START_PROFILE(name_7) $$ = Scm_AllReferencedInfoClear(); END_PROFILE(name_7) }
;

function_definition
	: declarator function_body { START_PROFILE(name_9) $$ = Scm_EmitDefineInline(name_8,$1,$2); END_PROFILE(name_9) }
	| declaration_specifiers declarator function_body { START_PROFILE(name_10) $$ = Scm_EmitDefineInline($1,$2,$3); END_PROFILE(name_10) }
;

function_body
	: compound_statement { START_PROFILE(name_12) $$ = Scm_ApplyRec1(name_11, $1); END_PROFILE(name_12) }
	| declaration_list compound_statement { START_PROFILE(name_13) $$ = SCM_FALSE; END_PROFILE(name_13) }
;

external_declaration
	: declaration_specifiers SEMICOLON { START_PROFILE(name_14) $$ = Scm_ExternalDeclaration($1,SCM_LIST1(Scm_NullDeclarator())); END_PROFILE(name_14) }
	| declaration_specifiers init_declarator_list SEMICOLON { START_PROFILE(name_15) $$ = Scm_ExternalDeclaration($1,$2); END_PROFILE(name_15) }
;

declaration
	: declaration_specifiers SEMICOLON { START_PROFILE(name_17) $$ = Scm_Declaration($1,name_16); END_PROFILE(name_17) }
	| declaration_specifiers init_declarator_list SEMICOLON { START_PROFILE(name_18) $$ = Scm_Declaration($1,$2); END_PROFILE(name_18) }
	| extension declaration { START_PROFILE(name_19) $$ = $2; END_PROFILE(name_19) }
;

declaration_specifiers
	: storage_class_specifier 
	| storage_class_specifier declaration_specifiers { START_PROFILE(name_20) $$ = CParser_Append($1,$2); END_PROFILE(name_20) }
	| type_specifier { START_PROFILE(name_21) $$ = $1; END_PROFILE(name_21) }
	| type_specifier declaration_specifiers { START_PROFILE(name_22) $$ = CParser_Append($1,$2); END_PROFILE(name_22) }
;

init_declarator_list
	: init_declarator { START_PROFILE(name_23) $$ = CParser_List(Scm_ComposeVariableAttribute($1)); END_PROFILE(name_23) }
	| init_declarator_list COMMA init_declarator { START_PROFILE(name_24) $$ = CParser_AddList($1,Scm_ComposeVariableAttribute($3)); END_PROFILE(name_24) }
;

init_declarator
	: declarator maybe_asm _3d initializer { START_PROFILE(name_25) $$ = Scm_ComposeDeclarator($1,Scm_InitValueDeclarator($4)); END_PROFILE(name_25) }
	| declarator maybe_asm { START_PROFILE(name_26) $$ = $1; END_PROFILE(name_26) }
;

storage_class_specifier
	: TYPEDEF { START_PROFILE(name_28) $$ = name_27; END_PROFILE(name_28) }
	| EXTERN { START_PROFILE(name_29) $$ = name_16; END_PROFILE(name_29) }
	| STATIC { START_PROFILE(name_30) $$ = name_16; END_PROFILE(name_30) }
	| AUTO { START_PROFILE(name_31) $$ = name_16; END_PROFILE(name_31) }
	| INLINE { START_PROFILE(name_32) $$ = name_16; END_PROFILE(name_32) }
;

type_specifier
	: TYPENAME { START_PROFILE(name_33) $$ = CParser_Typename($1); END_PROFILE(name_33) }
	| SIGNED { START_PROFILE(name_35) $$ = name_34; END_PROFILE(name_35) }
	| UNSIGNED { START_PROFILE(name_37) $$ = name_36; END_PROFILE(name_37) }
	| CONST { START_PROFILE(name_38) $$ = name_16; END_PROFILE(name_38) }
	| REGISTER { START_PROFILE(name_39) $$ = name_16; END_PROFILE(name_39) }
	| VOLATILE { START_PROFILE(name_40) $$ = name_16; END_PROFILE(name_40) }
	| struct_or_union_specifier { START_PROFILE(name_42) $$ = Scm_ApplyRec1(name_41, $1); END_PROFILE(name_42) }
	| enum_specifier { START_PROFILE(name_44) $$ = Scm_ApplyRec1(name_43, $1); END_PROFILE(name_44) }
	| RESTRICT { START_PROFILE(name_45) $$ = name_16; END_PROFILE(name_45) }
	| TYPENAME objc_non_empty_protocol_references { START_PROFILE(name_46) $$ = CParser_Typename($1); END_PROFILE(name_46) }
	| objc_non_empty_protocol_references { START_PROFILE(name_48) $$ = name_47; END_PROFILE(name_48) }
;

primary_expr
	: identifier { START_PROFILE(name_50) $$ = Scm_ApplyRec1(name_49, $1); END_PROFILE(name_50) }
	| CONSTANT { START_PROFILE(name_51) $$ = $1; END_PROFILE(name_51) }
	| STRING { START_PROFILE(name_52) $$ = $1; END_PROFILE(name_52) }
	| OBJC_STRING { START_PROFILE(name_54) $$ = Scm_ApplyRec1(name_53, $1); END_PROFILE(name_54) }
	| LPAREN expr RPAREN { START_PROFILE(name_56) $$ = Scm_ApplyRec1(name_55, $2); END_PROFILE(name_56) }
	| LPAREN compound_statement RPAREN { START_PROFILE(name_58) $$ = Scm_ApplyRec1(name_57, $2); END_PROFILE(name_58) }
	| LPAREN type_name RPAREN LCBRA initializer_list RCBRA { START_PROFILE(name_59) $$ = SCM_FALSE; END_PROFILE(name_59) }
	| objc_message_expr { START_PROFILE(name_60) $$ = $1; END_PROFILE(name_60) }
	| objc_selector_expr { START_PROFILE(name_61) $$ = $1; END_PROFILE(name_61) }
	| objc_protocol_expr { START_PROFILE(name_62) $$ = SCM_FALSE; END_PROFILE(name_62) }
	| objc_encode_expr { START_PROFILE(name_63) $$ = SCM_FALSE; END_PROFILE(name_63) }
;

postfix_expr
	: primary_expr { START_PROFILE(name_64) $$ = $1; END_PROFILE(name_64) }
	| postfix_expr LSBRA expr RSBRA { START_PROFILE(name_66) $$ = Scm_ApplyRec2(name_65, $1, $3); END_PROFILE(name_66) }
	| postfix_expr LPAREN RPAREN { START_PROFILE(name_68) $$ = Scm_ApplyRec2(name_67, $1, name_16); END_PROFILE(name_68) }
	| postfix_expr LPAREN argument_expr_list RPAREN { START_PROFILE(name_69) $$ = Scm_ApplyRec2(name_67, $1, $3); END_PROFILE(name_69) }
	| postfix_expr DOT identifier { START_PROFILE(name_71) $$ = Scm_ApplyRec2(name_70, $1, $3); END_PROFILE(name_71) }
	| postfix_expr PTR_OP identifier { START_PROFILE(name_73) $$ = Scm_ApplyRec2(name_72, $1, $3); END_PROFILE(name_73) }
	| postfix_expr INC_OP { START_PROFILE(name_75) $$ = Scm_ApplyRec1(name_74, $1); END_PROFILE(name_75) }
	| postfix_expr DEC_OP { START_PROFILE(name_77) $$ = Scm_ApplyRec1(name_76, $1); END_PROFILE(name_77) }
;

argument_expr_list
	: assignment_expr { START_PROFILE(name_78) $$ = CParser_List($1); END_PROFILE(name_78) }
	| argument_expr_list COMMA assignment_expr { START_PROFILE(name_79) $$ = CParser_AddList($1,$3); END_PROFILE(name_79) }
;

unary_expr
	: postfix_expr { START_PROFILE(name_80) $$ = $1; END_PROFILE(name_80) }
	| INC_OP unary_expr { START_PROFILE(name_82) $$ = Scm_ApplyRec1(name_81, $2); END_PROFILE(name_82) }
	| DEC_OP unary_expr { START_PROFILE(name_84) $$ = Scm_ApplyRec1(name_83, $2); END_PROFILE(name_84) }
	| unary_operator cast_expr { START_PROFILE(name_86) $$ = Scm_ApplyRec2(name_85, $1, $2); END_PROFILE(name_86) }
	| SIZEOF unary_expr { START_PROFILE(name_88) $$ = Scm_ApplyRec1(name_87, $2); END_PROFILE(name_88) }
	| SIZEOF LPAREN type_name RPAREN { START_PROFILE(name_90) $$ = Scm_ApplyRec1(name_89, $3); END_PROFILE(name_90) }
	| extension cast_expr { START_PROFILE(name_91) $$ = $2; END_PROFILE(name_91) }
;

unary_operator
	: _26 { START_PROFILE(name_92) $$ = token_sym__26; END_PROFILE(name_92) }
	| _2a { START_PROFILE(name_93) $$ = token_sym__2a; END_PROFILE(name_93) }
	| _2b { START_PROFILE(name_94) $$ = token_sym__2b; END_PROFILE(name_94) }
	| _ { START_PROFILE(name_95) $$ = token_sym__; END_PROFILE(name_95) }
	| _7e { START_PROFILE(name_96) $$ = token_sym__7e; END_PROFILE(name_96) }
	| X { START_PROFILE(name_97) $$ = token_sym_X; END_PROFILE(name_97) }
;

cast_expr
	: unary_expr { START_PROFILE(name_98) $$ = $1; END_PROFILE(name_98) }
	| LPAREN type_name RPAREN cast_expr { START_PROFILE(name_100) $$ = Scm_ApplyRec2(name_99, $2, $4); END_PROFILE(name_100) }
;

multiplicative_expr
	: cast_expr { START_PROFILE(name_101) $$ = $1; END_PROFILE(name_101) }
	| multiplicative_expr _2a cast_expr { START_PROFILE(name_103) $$ = Scm_ApplyRec2(name_102, $1, $3); END_PROFILE(name_103) }
	| multiplicative_expr _2f cast_expr { START_PROFILE(name_105) $$ = Scm_ApplyRec2(name_104, $1, $3); END_PROFILE(name_105) }
	| multiplicative_expr _25 cast_expr { START_PROFILE(name_107) $$ = Scm_ApplyRec2(name_106, $1, $3); END_PROFILE(name_107) }
;

additive_expr
	: multiplicative_expr { START_PROFILE(name_108) $$ = $1; END_PROFILE(name_108) }
	| additive_expr _2b multiplicative_expr { START_PROFILE(name_110) $$ = Scm_ApplyRec2(name_109, $1, $3); END_PROFILE(name_110) }
	| additive_expr _ multiplicative_expr { START_PROFILE(name_112) $$ = Scm_ApplyRec2(name_111, $1, $3); END_PROFILE(name_112) }
;

shift_expr
	: additive_expr { START_PROFILE(name_113) $$ = $1; END_PROFILE(name_113) }
	| shift_expr LEFT_OP additive_expr { START_PROFILE(name_115) $$ = Scm_ApplyRec2(name_114, $1, $3); END_PROFILE(name_115) }
	| shift_expr RIGHT_OP additive_expr { START_PROFILE(name_117) $$ = Scm_ApplyRec2(name_116, $1, $3); END_PROFILE(name_117) }
;

relational_expr
	: shift_expr { START_PROFILE(name_118) $$ = $1; END_PROFILE(name_118) }
	| relational_expr _LT shift_expr { START_PROFILE(name_120) $$ = Scm_ApplyRec2(name_119, $1, $3); END_PROFILE(name_120) }
	| relational_expr _GT shift_expr { START_PROFILE(name_122) $$ = Scm_ApplyRec2(name_121, $1, $3); END_PROFILE(name_122) }
	| relational_expr LE_OP shift_expr { START_PROFILE(name_124) $$ = Scm_ApplyRec2(name_123, $1, $3); END_PROFILE(name_124) }
	| relational_expr GE_OP shift_expr { START_PROFILE(name_126) $$ = Scm_ApplyRec2(name_125, $1, $3); END_PROFILE(name_126) }
;

equality_expr
	: relational_expr { START_PROFILE(name_127) $$ = $1; END_PROFILE(name_127) }
	| equality_expr EQ_OP relational_expr { START_PROFILE(name_129) $$ = Scm_ApplyRec2(name_128, $1, $3); END_PROFILE(name_129) }
	| equality_expr NE_OP relational_expr { START_PROFILE(name_131) $$ = Scm_ApplyRec2(name_130, $1, $3); END_PROFILE(name_131) }
;

and_expr
	: equality_expr { START_PROFILE(name_132) $$ = $1; END_PROFILE(name_132) }
	| and_expr _26 equality_expr { START_PROFILE(name_134) $$ = Scm_ApplyRec2(name_133, $1, $3); END_PROFILE(name_134) }
;

exclusive_or_expr
	: and_expr { START_PROFILE(name_135) $$ = $1; END_PROFILE(name_135) }
	| exclusive_or_expr _5e and_expr { START_PROFILE(name_137) $$ = Scm_ApplyRec2(name_136, $1, $3); END_PROFILE(name_137) }
;

inclusive_or_expr
	: exclusive_or_expr { START_PROFILE(name_138) $$ = $1; END_PROFILE(name_138) }
	| inclusive_or_expr OR exclusive_or_expr { START_PROFILE(name_140) $$ = Scm_ApplyRec2(name_139, $1, $3); END_PROFILE(name_140) }
;

logical_and_expr
	: inclusive_or_expr { START_PROFILE(name_141) $$ = $1; END_PROFILE(name_141) }
	| logical_and_expr AND_OP inclusive_or_expr { START_PROFILE(name_143) $$ = Scm_ApplyRec2(name_142, $1, $3); END_PROFILE(name_143) }
;

logical_or_expr
	: logical_and_expr { START_PROFILE(name_144) $$ = $1; END_PROFILE(name_144) }
	| logical_or_expr OR_OP logical_and_expr { START_PROFILE(name_146) $$ = Scm_ApplyRec2(name_145, $1, $3); END_PROFILE(name_146) }
;

conditional_expr
	: logical_or_expr { START_PROFILE(name_147) $$ = $1; END_PROFILE(name_147) }
	| logical_or_expr P logical_or_expr COLON conditional_expr { START_PROFILE(name_149) $$ = Scm_ApplyRec3(name_148, $1, $3, $5); END_PROFILE(name_149) }
;

assignment_expr
	: conditional_expr { START_PROFILE(name_150) $$ = $1; END_PROFILE(name_150) }
	| unary_expr _3d assignment_expr { START_PROFILE(name_152) $$ = Scm_ApplyRec2(name_151, $1, $3); END_PROFILE(name_152) }
	| unary_expr MUL_ASSIGN assignment_expr { START_PROFILE(name_153) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_102, $1, $3)); END_PROFILE(name_153) }
	| unary_expr DIV_ASSIGN assignment_expr { START_PROFILE(name_154) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_104, $1, $3)); END_PROFILE(name_154) }
	| unary_expr MOD_ASSIGN assignment_expr { START_PROFILE(name_155) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_106, $1, $3)); END_PROFILE(name_155) }
	| unary_expr ADD_ASSIGN assignment_expr { START_PROFILE(name_156) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_109, $1, $3)); END_PROFILE(name_156) }
	| unary_expr SUB_ASSIGN assignment_expr { START_PROFILE(name_157) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_111, $1, $3)); END_PROFILE(name_157) }
	| unary_expr LEFT_ASSIGN assignment_expr { START_PROFILE(name_158) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_114, $1, $3)); END_PROFILE(name_158) }
	| unary_expr RIGHT_ASSIGN assignment_expr { START_PROFILE(name_159) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_116, $1, $3)); END_PROFILE(name_159) }
	| unary_expr AND_ASSIGN assignment_expr { START_PROFILE(name_160) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_133, $1, $3)); END_PROFILE(name_160) }
	| unary_expr XOR_ASSIGN assignment_expr { START_PROFILE(name_161) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_136, $1, $3)); END_PROFILE(name_161) }
	| unary_expr OR_ASSIGN assignment_expr { START_PROFILE(name_162) $$ = Scm_ApplyRec2(name_151, $1, Scm_ApplyRec2(name_139, $1, $3)); END_PROFILE(name_162) }
;

expr
	: assignment_expr { START_PROFILE(name_163) $$ = $1; END_PROFILE(name_163) }
	| expr COMMA assignment_expr { START_PROFILE(name_165) $$ = Scm_ApplyRec2(name_164, $1, $3); END_PROFILE(name_165) }
;

constant_expr
	: conditional_expr { START_PROFILE(name_166) $$ = $1; END_PROFILE(name_166) }
;

struct_or_union_specifier
	: struct_or_union identifier LCBRA struct_declaration_list RCBRA { START_PROFILE(name_168) $$ = Scm_ApplyRec3(name_167, $1, $2, $4); END_PROFILE(name_168) }
	| struct_or_union LCBRA struct_declaration_list RCBRA { START_PROFILE(name_169) $$ = Scm_ApplyRec3(name_167, $1, SCM_FALSE, $3); END_PROFILE(name_169) }
	| struct_or_union identifier { START_PROFILE(name_170) $$ = Scm_ApplyRec3(name_167, $1, $2, SCM_FALSE); END_PROFILE(name_170) }
;

struct_or_union
	: STRUCT { START_PROFILE(name_171) $$ = token_sym_STRUCT; END_PROFILE(name_171) }
	| UNION { START_PROFILE(name_172) $$ = token_sym_UNION; END_PROFILE(name_172) }
;

struct_declaration_list
	: struct_declaration { START_PROFILE(name_173) $$ = $1; END_PROFILE(name_173) }
	| struct_declaration_list struct_declaration { START_PROFILE(name_174) $$ = CParser_Append($1,$2); END_PROFILE(name_174) }
;

struct_declaration
	: type_specifier_list struct_declarator_list SEMICOLON { START_PROFILE(name_176) Scm_ApplyRec0(name_175); $$ = Scm_MakeTypeDeclList($1,$2); END_PROFILE(name_176) }
	| extension type_specifier_list struct_declarator_list SEMICOLON { START_PROFILE(name_177) Scm_ApplyRec0(name_175); $$ = Scm_MakeTypeDeclList($2,$3); END_PROFILE(name_177) }
	| struct_or_union_specifier SEMICOLON { START_PROFILE(name_180) Scm_ApplyRec0(name_175); $$ = Scm_MakeTypeDeclList(CParser_List($1),SCM_LIST1(Scm_IdentifierDeclarator(Scm_ApplyRec1(name_178, name_179)))); END_PROFILE(name_180) }
	| extension struct_or_union_specifier SEMICOLON { START_PROFILE(name_181) Scm_ApplyRec0(name_175); $$ = Scm_MakeTypeDeclList(CParser_List($2),SCM_LIST1(Scm_IdentifierDeclarator(Scm_ApplyRec1(name_178, name_179)))); END_PROFILE(name_181) }
	| AT_DEFS LPAREN TYPENAME RPAREN { START_PROFILE(name_182) $$ = name_16; END_PROFILE(name_182) }
;

struct_declarator_list
	: struct_declarator { START_PROFILE(name_183) $$ = CParser_List(Scm_ComposeVariableAttribute($1)); END_PROFILE(name_183) }
	| struct_declarator_list COMMA struct_declarator { START_PROFILE(name_184) $$ = CParser_AddList($1,Scm_ComposeVariableAttribute($3)); END_PROFILE(name_184) }
;

struct_declarator
	: declarator { START_PROFILE(name_185) $$ = $1; END_PROFILE(name_185) }
	| COLON constant_expr { START_PROFILE(name_186) $$ = Scm_BitFieldDeclarator($2); END_PROFILE(name_186) }
	| declarator COLON constant_expr { START_PROFILE(name_187) $$ = Scm_ComposeDeclarator(Scm_BitFieldDeclarator($3),$1); END_PROFILE(name_187) }
;

enum_specifier
	: ENUM LCBRA enumerator_list RCBRA { START_PROFILE(name_189) $$ = Scm_ApplyRec2(name_188, SCM_FALSE, $3); END_PROFILE(name_189) }
	| ENUM LCBRA enumerator_list COMMA RCBRA { START_PROFILE(name_190) $$ = Scm_ApplyRec2(name_188, SCM_FALSE, $3); END_PROFILE(name_190) }
	| ENUM identifier LCBRA enumerator_list RCBRA { START_PROFILE(name_191) $$ = Scm_ApplyRec2(name_188, $2, $4); END_PROFILE(name_191) }
	| ENUM identifier LCBRA enumerator_list COMMA RCBRA { START_PROFILE(name_192) $$ = Scm_ApplyRec2(name_188, $2, $4); END_PROFILE(name_192) }
	| ENUM identifier { START_PROFILE(name_193) $$ = Scm_ApplyRec2(name_188, $2, name_16); END_PROFILE(name_193) }
;

enumerator_list
	: enumerator { START_PROFILE(name_194) $$ = CParser_List($1); END_PROFILE(name_194) }
	| enumerator_list COMMA enumerator { START_PROFILE(name_195) $$ = CParser_AddList($1,$3); END_PROFILE(name_195) }
;

enumerator
	: identifier { START_PROFILE(name_197) $$ = Scm_ApplyRec2(name_196, $1, SCM_FALSE); END_PROFILE(name_197) }
	| identifier _3d constant_expr { START_PROFILE(name_198) $$ = Scm_ApplyRec2(name_196, $1, $3); END_PROFILE(name_198) }
;

declarator
	: declarator2 { START_PROFILE(name_199) $$ = $1; END_PROFILE(name_199) }
	| pointer declarator2 { START_PROFILE(name_200) $$ = Scm_ComposeDeclarator($2,$1); END_PROFILE(name_200) }
;

declarator2
	: identifier { START_PROFILE(name_201) $$ = Scm_IdentifierDeclarator($1); END_PROFILE(name_201) }
	| LPAREN declarator RPAREN { START_PROFILE(name_202) $$ = $2; END_PROFILE(name_202) }
	| declarator2 LSBRA RSBRA { START_PROFILE(name_203) $$ = Scm_ComposeDeclarator(Scm_ArrayDeclarator(SCM_FALSE),$1); END_PROFILE(name_203) }
	| declarator2 LSBRA array_qualifier_list RSBRA { START_PROFILE(name_204) $$ = Scm_ComposeDeclarator(Scm_ArrayDeclarator(SCM_FALSE),$1); END_PROFILE(name_204) }
	| declarator2 LSBRA array_size_expr RSBRA { START_PROFILE(name_205) $$ = Scm_ComposeDeclarator(Scm_ArrayDeclarator($3),$1); END_PROFILE(name_205) }
	| declarator2 LSBRA array_qualifier_list array_size_expr RSBRA { START_PROFILE(name_206) $$ = Scm_ComposeDeclarator(Scm_ArrayDeclarator($4),$1); END_PROFILE(name_206) }
	| declarator2 LPAREN RPAREN { START_PROFILE(name_207) $$ = Scm_ComposeDeclarator($1,Scm_FuncDeclarator(name_16)); END_PROFILE(name_207) }
	| declarator2 LPAREN parameter_type_list RPAREN { START_PROFILE(name_208) $$ = Scm_ComposeDeclarator($1,$3); END_PROFILE(name_208) }
	| declarator2 LPAREN parameter_identifier_list RPAREN { START_PROFILE(name_209) $$ = $1; END_PROFILE(name_209) }
;

pointer
	: _2a { START_PROFILE(name_210) $$ = Scm_PtrDeclarator(); END_PROFILE(name_210) }
	| _2a type_specifier_list { START_PROFILE(name_211) $$ = Scm_PtrDeclarator(); END_PROFILE(name_211) }
	| _2a pointer { START_PROFILE(name_212) $$ = Scm_ComposeDeclarator(Scm_PtrDeclarator(),$2); END_PROFILE(name_212) }
	| _2a type_specifier_list pointer { START_PROFILE(name_213) $$ = Scm_ComposeDeclarator(Scm_PtrDeclarator(),$3); END_PROFILE(name_213) }
;

type_specifier_list
	: type_specifier { START_PROFILE(name_214) $$ = $1; END_PROFILE(name_214) }
	| type_specifier_list type_specifier { START_PROFILE(name_215) $$ = CParser_Append($1,$2); END_PROFILE(name_215) }
;

parameter_identifier_list
	: identifier_list 
	| identifier_list COMMA ELLIPSIS 
;

identifier_list
	: identifier { START_PROFILE(name_216) $$ = CParser_List($1); END_PROFILE(name_216) }
	| identifier_list COMMA identifier { START_PROFILE(name_217) $$ = CParser_AddList($1,$3); END_PROFILE(name_217) }
;

parameter_type_list
	: parameter_list { START_PROFILE(name_218) $$ = Scm_FuncDeclarator($1); END_PROFILE(name_218) }
	| parameter_list COMMA ELLIPSIS { START_PROFILE(name_219) $$ = Scm_FuncVaargsDeclarator($1); END_PROFILE(name_219) }
;

parameter_list
	: parameter_declaration { START_PROFILE(name_220) $$ = CParser_List($1); END_PROFILE(name_220) }
	| parameter_list COMMA parameter_declaration { START_PROFILE(name_221) $$ = CParser_AddList($1,$3); END_PROFILE(name_221) }
;

parameter_declaration
	: type_specifier_list declarator { START_PROFILE(name_222) $$ = Scm_ParameterDeclaration(Scm_MakeTypeDecl($1,Scm_ComposeVariableAttribute($2))); END_PROFILE(name_222) }
	| type_name { START_PROFILE(name_223) $$ = $1; END_PROFILE(name_223) }
;

type_name
	: type_specifier_list { START_PROFILE(name_224) $$ = Scm_MakeTypeDecl($1,Scm_NullDeclarator()); END_PROFILE(name_224) }
	| type_specifier_list abstract_declarator { START_PROFILE(name_225) $$ = Scm_MakeTypeDecl($1,$2); END_PROFILE(name_225) }
;

abstract_declarator
	: pointer { START_PROFILE(name_226) $$ = $1; END_PROFILE(name_226) }
	| abstract_declarator2 { START_PROFILE(name_227) $$ = $1; END_PROFILE(name_227) }
	| pointer abstract_declarator2 { START_PROFILE(name_228) $$ = Scm_ComposeDeclarator($2,$1); END_PROFILE(name_228) }
;

abstract_declarator2
	: LPAREN abstract_declarator RPAREN { START_PROFILE(name_229) $$ = $2; END_PROFILE(name_229) }
	| LSBRA RSBRA { START_PROFILE(name_230) $$ = Scm_PtrDeclarator(); END_PROFILE(name_230) }
	| LSBRA array_qualifier_list RSBRA { START_PROFILE(name_231) $$ = Scm_PtrDeclarator(); END_PROFILE(name_231) }
	| LSBRA array_size_expr RSBRA { START_PROFILE(name_232) $$ = Scm_ArrayDeclarator($2); END_PROFILE(name_232) }
	| LSBRA array_qualifier_list array_size_expr RSBRA { START_PROFILE(name_233) $$ = Scm_ArrayDeclarator($3); END_PROFILE(name_233) }
	| abstract_declarator2 LSBRA RSBRA { START_PROFILE(name_234) $$ = Scm_ComposeDeclarator(Scm_PtrDeclarator(),$1); END_PROFILE(name_234) }
	| abstract_declarator2 LSBRA array_qualifier_list RSBRA { START_PROFILE(name_235) $$ = Scm_ComposeDeclarator(Scm_PtrDeclarator(),$1); END_PROFILE(name_235) }
	| abstract_declarator2 LSBRA array_size_expr RSBRA { START_PROFILE(name_236) $$ = Scm_ComposeDeclarator(Scm_ArrayDeclarator($3),$1); END_PROFILE(name_236) }
	| abstract_declarator2 LSBRA array_qualifier_list array_size_expr RSBRA { START_PROFILE(name_237) $$ = Scm_ComposeDeclarator(Scm_ArrayDeclarator($4),$1); END_PROFILE(name_237) }
	| LPAREN RPAREN { START_PROFILE(name_238) $$ = Scm_FuncDeclarator(name_16); END_PROFILE(name_238) }
	| LPAREN parameter_type_list RPAREN { START_PROFILE(name_239) $$ = $2; END_PROFILE(name_239) }
	| abstract_declarator2 LPAREN RPAREN { START_PROFILE(name_240) $$ = Scm_ComposeDeclarator($1,Scm_FuncDeclarator(name_16)); END_PROFILE(name_240) }
	| abstract_declarator2 LPAREN parameter_type_list RPAREN { START_PROFILE(name_241) $$ = Scm_ComposeDeclarator($1,$3); END_PROFILE(name_241) }
;

initializer
	: assignment_expr { START_PROFILE(name_242) $$ = $1; END_PROFILE(name_242) }
	| LCBRA initializer_list RCBRA { START_PROFILE(name_243) $$ = SCM_FALSE; END_PROFILE(name_243) }
	| LCBRA initializer_list COMMA RCBRA { START_PROFILE(name_244) $$ = SCM_FALSE; END_PROFILE(name_244) }
;

initializer_list
	: initializer 
	| initializer_list COMMA initializer 
;

statement
	: labeled_statement { START_PROFILE(name_245) $$ = SCM_FALSE; END_PROFILE(name_245) }
	| compound_statement { START_PROFILE(name_246) $$ = $1; END_PROFILE(name_246) }
	| expression_statement { START_PROFILE(name_247) $$ = $1; END_PROFILE(name_247) }
	| selection_statement { START_PROFILE(name_248) $$ = $1; END_PROFILE(name_248) }
	| iteration_statement { START_PROFILE(name_249) $$ = $1; END_PROFILE(name_249) }
	| jump_statement { START_PROFILE(name_250) $$ = $1; END_PROFILE(name_250) }
	| asm_statement { START_PROFILE(name_251) $$ = SCM_FALSE; END_PROFILE(name_251) }
	| objc_statement { START_PROFILE(name_252) $$ = SCM_FALSE; END_PROFILE(name_252) }
;

objc_statement
	: AT_THROW expr SEMICOLON 
	| AT_THROW SEMICOLON 
	| objc_try_catch_statement 
	| AT_SYNCHRONIZED LPAREN expr RPAREN compound_statement 
;

objc_catch_prefix
	: AT_CATCH LPAREN identifier RPAREN 
;

objc_catch_clause
	: objc_catch_prefix compound_statement 
;

objc_opt_catch_list
	:  
	| objc_opt_catch_list objc_catch_clause 
;

objc_try_catch_clause
	: AT_TRY compound_statement objc_opt_catch_list 
;

objc_finally_clause
	: AT_FINALLY compound_statement 
;

objc_try_catch_statement
	: objc_try_catch_clause 
	| objc_try_catch_clause objc_finally_clause 
;

labeled_statement
	: identifier COLON statement 
	| CASE constant_expr COLON statement 
	| DEFAULT COLON statement 
;

compound_statement
	: LCBRA RCBRA { START_PROFILE(name_254) $$ = Scm_ApplyRec1(name_57, name_253); END_PROFILE(name_254) }
	| LCBRA statement_list RCBRA { START_PROFILE(name_255) $$ = Scm_ApplyRec1(name_57, $2); END_PROFILE(name_255) }
	| LCBRA declaration_list RCBRA { START_PROFILE(name_256) $$ = Scm_ApplyRec1(name_57, name_253); END_PROFILE(name_256) }
	| LCBRA declaration_list statement_list RCBRA { START_PROFILE(name_258) $$ = Scm_ApplyRec2(name_257, $2, $3); END_PROFILE(name_258) }
	| error RCBRA { START_PROFILE(name_259) $$ = SCM_FALSE; END_PROFILE(name_259) }
;

declaration_list
	: declaration { START_PROFILE(name_260) $$ = $1; END_PROFILE(name_260) }
	| declaration_list declaration { START_PROFILE(name_261) $$ = CParser_Append($1,$2); END_PROFILE(name_261) }
;

statement_list
	: statement { START_PROFILE(name_262) $$ = CParser_List($1); END_PROFILE(name_262) }
	| statement_list statement { START_PROFILE(name_263) $$ = CParser_AddList($1,$2); END_PROFILE(name_263) }
;

expression_statement
	: SEMICOLON { START_PROFILE(name_264) $$ = SCM_MAKE_INT(0); END_PROFILE(name_264) }
	| expr SEMICOLON { START_PROFILE(name_265) $$ = $1; END_PROFILE(name_265) }
	| error SEMICOLON { START_PROFILE(name_266) $$ = SCM_FALSE; END_PROFILE(name_266) }
;

selection_statement
	: IF LPAREN expr RPAREN statement { START_PROFILE(name_267) $$ = Scm_ApplyRec3(name_148, $3, $5, SCM_MAKE_INT(0)); END_PROFILE(name_267) }
	| IF LPAREN expr RPAREN statement ELSE statement { START_PROFILE(name_268) $$ = Scm_ApplyRec3(name_148, $3, $5, $7); END_PROFILE(name_268) }
	| SWITCH LPAREN expr RPAREN statement { START_PROFILE(name_269) $$ = SCM_FALSE; END_PROFILE(name_269) }
;

iteration_statement
	: WHILE LPAREN expr RPAREN statement { START_PROFILE(name_271) $$ = Scm_ApplyRec2(name_270, $3, $5); END_PROFILE(name_271) }
	| DO statement WHILE LPAREN expr RPAREN SEMICOLON { START_PROFILE(name_273) $$ = Scm_ApplyRec2(name_272, $5, $2); END_PROFILE(name_273) }
	| FOR LPAREN SEMICOLON SEMICOLON RPAREN statement { START_PROFILE(name_275) $$ = Scm_ApplyRec4(name_274, SCM_MAKE_INT(0), SCM_MAKE_INT(1), SCM_MAKE_INT(0), $6); END_PROFILE(name_275) }
	| FOR LPAREN SEMICOLON SEMICOLON expr RPAREN statement { START_PROFILE(name_276) $$ = Scm_ApplyRec4(name_274, SCM_MAKE_INT(0), SCM_MAKE_INT(1), $5, $7); END_PROFILE(name_276) }
	| FOR LPAREN SEMICOLON expr SEMICOLON RPAREN statement { START_PROFILE(name_277) $$ = Scm_ApplyRec4(name_274, SCM_MAKE_INT(0), $4, SCM_MAKE_INT(0), $7); END_PROFILE(name_277) }
	| FOR LPAREN SEMICOLON expr SEMICOLON expr RPAREN statement { START_PROFILE(name_278) $$ = Scm_ApplyRec4(name_274, SCM_MAKE_INT(0), $4, $6, $8); END_PROFILE(name_278) }
	| FOR LPAREN expr SEMICOLON SEMICOLON RPAREN statement { START_PROFILE(name_279) $$ = Scm_ApplyRec4(name_274, $3, SCM_MAKE_INT(1), SCM_MAKE_INT(0), $7); END_PROFILE(name_279) }
	| FOR LPAREN expr SEMICOLON SEMICOLON expr RPAREN statement { START_PROFILE(name_280) $$ = Scm_ApplyRec4(name_274, $3, SCM_MAKE_INT(1), $6, $8); END_PROFILE(name_280) }
	| FOR LPAREN expr SEMICOLON expr SEMICOLON RPAREN statement { START_PROFILE(name_281) $$ = Scm_ApplyRec4(name_274, $3, $5, SCM_MAKE_INT(0), $8); END_PROFILE(name_281) }
	| FOR LPAREN expr SEMICOLON expr SEMICOLON expr RPAREN statement { START_PROFILE(name_282) $$ = Scm_ApplyRec4(name_274, $3, $5, $7, $9); END_PROFILE(name_282) }
;

jump_statement
	: GOTO identifier SEMICOLON { START_PROFILE(name_283) $$ = SCM_FALSE; END_PROFILE(name_283) }
	| CONTINUE SEMICOLON { START_PROFILE(name_285) $$ = Scm_ApplyRec0(name_284); END_PROFILE(name_285) }
	| BREAK SEMICOLON { START_PROFILE(name_287) $$ = Scm_ApplyRec0(name_286); END_PROFILE(name_287) }
	| RETURN SEMICOLON { START_PROFILE(name_289) $$ = Scm_ApplyRec1(name_288, SCM_MAKE_INT(0)); END_PROFILE(name_289) }
	| RETURN expr SEMICOLON { START_PROFILE(name_290) $$ = Scm_ApplyRec1(name_288, $2); END_PROFILE(name_290) }
;

identifier
	: IDENTIFIER { START_PROFILE(name_291) $$ = $1; END_PROFILE(name_291) }
;

maybe_asm
	:  
	| asm_expr 
;

asm_expr
	: ASM LPAREN string_list RPAREN 
;

asm_statement
	: ASM LPAREN asm_argument RPAREN SEMICOLON 
	| ASM type_qualifier LPAREN asm_argument RPAREN SEMICOLON 
;

type_qualifier
	: CONST 
	| VOLATILE 
	| RESTRICT 
;

array_qualifier
	: STATIC 
	| RESTRICT 
	| CONST 
	| VOLATILE 
;

array_qualifier_list
	: array_qualifier 
	| array_qualifier_list array_qualifier 
;

array_size_expr
	: assignment_expr { START_PROFILE(name_292) $$ = $1; END_PROFILE(name_292) }
	| _2a { START_PROFILE(name_293) $$ = SCM_FALSE; END_PROFILE(name_293) }
;

asm_argument
	: string_list 
	| string_list COLON asm_operands 
	| string_list COLON asm_operands COLON asm_operands 
	| string_list COLON asm_operands COLON asm_operands COLON asm_clobbers 
;

string_list
	: STRING 
	| string_list STRING 
;

asm_operands
	:  
	| asm_operands2 
;

asm_operands2
	: asm_operand 
	| asm_operands2 COMMA asm_operand 
;

asm_operand
	: STRING LPAREN expr RPAREN 
	| LSBRA identifier RSBRA STRING LPAREN expr RPAREN 
;

asm_clobbers
	: STRING 
	| asm_clobbers COMMA STRING 
;

asm_definition
	: asm_expr SEMICOLON 
;

maybe_extension
	:  
	| extension 
;

extension
	: EXTENSION 
;

objc_definition
	: objc_class_definition 
	| objc_class_declaration 
	| objc_alias_declaration 
	| objc_protocol_definition 
	| objc_method_definition 
;

classname
	: identifier { START_PROFILE(name_294) $$ = $1; END_PROFILE(name_294) }
	| TYPENAME { START_PROFILE(name_295) $$ = $1; END_PROFILE(name_295) }
;

classname_list
	: classname { START_PROFILE(name_296) $$ = CParser_List($1); END_PROFILE(name_296) }
	| classname_list COMMA classname { START_PROFILE(name_297) $$ = CParser_AddList($1,$3); END_PROFILE(name_297) }
;

objc_class_declaration
	: AT_CLASS classname_list SEMICOLON { START_PROFILE(name_298) $$ = Scm_EmitDefineObjcClass($2); END_PROFILE(name_298) }
;

objc_alias_declaration
	: AT_ALIAS identifier identifier SEMICOLON { START_PROFILE(name_299) $$ = SCM_FALSE; END_PROFILE(name_299) }
;

objc_superclass
	: COLON classname 
	|  
;

objc_class_ivars
	: LCBRA objc_ivar_declaration_list RCBRA 
	|  
;

objc_class_definition
	: objc_interface_head objc_superclass objc_protocol_references objc_class_ivars objc_method_prototype_list AT_END 
	| AT_IMPLEMENTATION classname objc_superclass objc_class_ivars 
	| objc_interface_head LPAREN classname RPAREN objc_protocol_references objc_method_prototype_list AT_END 
	| AT_IMPLEMENTATION classname LPAREN identifier RPAREN 
;

objc_interface_head
	: AT_INTERFACE classname { START_PROFILE(name_300) $$ = Scm_EmitDefineObjcClass(CParser_List($2)); END_PROFILE(name_300) }
;

objc_protocol_definition
	: AT_PROTOCOL identifier objc_protocol_references objc_method_prototype_list AT_END 
	| AT_PROTOCOL identifier_list SEMICOLON 
;

objc_protocol_references
	:  
	| objc_non_empty_protocol_references 
;

objc_non_empty_protocol_references
	: _LT classname_list _GT 
;

objc_ivar_declaration_list
	: objc_ivar_declaration_list objc_visibility_spec objc_ivar_declarations 
	| objc_ivar_declarations 
;

objc_visibility_spec
	: AT_PRIVATE 
	| AT_PROTECTED 
	| AT_PUBLIC 
	| AT_PACKAGE 
;

objc_ivar_declarations
	:  
	| objc_ivar_declarations objc_ivar_declaration SEMICOLON 
	| objc_ivar_declarations SEMICOLON 
;

objc_ivar_declaration
	: declaration_specifiers objc_ivars 
;

objc_ivars
	:  
	| objc_ivar_declarator 
	| objc_ivars COMMA objc_ivar_declarator 
;

objc_ivar_declarator
	: declarator 
	| declarator COLON assignment_expr 
	| COLON assignment_expr 
;

objc_method_type
	: _2b 
	| _ 
;

objc_method_definition
	: objc_method_type objc_method_declaration optarglist compound_statement 
;

objc_method_prototype_list
	:  
	| objc_method_prototype_list objc_method_prototype 
	| objc_method_prototype_list external_declaration 
	| objc_method_prototype_list objc_property 
	| objc_method_prototype_list AT_OPTIONAL 
	| objc_method_prototype_list AT_REQUIRED 
;

objc_method_prototype
	: objc_method_type objc_method_declaration SEMICOLON { START_PROFILE(name_303) Scm_ApplyRec0(name_175); $$ = Scm_ApplyRec2(name_301, name_302, $2); END_PROFILE(name_303) }
;

objc_property
	: AT_PROPERTY LPAREN property_attribute_list RPAREN declaration 
	| AT_PROPERTY declaration 
	| AT_SYNTHESIZE init_declarator_list SEMICOLON 
	| AT_DYNAMIC init_declarator_list SEMICOLON 
;

property_attribute_list
	:  
	| identifier 
	| property_attribute_list COMMA identifier 
;

objc_protocol_qualifier
	:  
	| identifier 
;

objc_method_declaration
	: LPAREN objc_protocol_qualifier type_name RPAREN unary_selector { START_PROFILE(name_305) $$ = Scm_ApplyRec2(name_304, $3, $5); END_PROFILE(name_305) }
	| unary_selector { START_PROFILE(name_307) $$ = Scm_ApplyRec2(name_304, Scm_ApplyRec0(name_306), $1); END_PROFILE(name_307) }
	| LPAREN objc_protocol_qualifier type_name RPAREN keyword_selector optparmlist { START_PROFILE(name_308) $$ = Scm_ApplyRec2(name_304, $3, $5); END_PROFILE(name_308) }
	| keyword_selector optparmlist { START_PROFILE(name_309) $$ = Scm_ApplyRec2(name_304, Scm_ApplyRec0(name_306), $1); END_PROFILE(name_309) }
;

optarglist
	:  
	| SEMICOLON myxdecls 
;

myxdecls
	:  
	| mydecls 
;

error_statement
	: error SEMICOLON { START_PROFILE(name_310) $$ = SCM_FALSE; END_PROFILE(name_310) }
;

mydecls
	: mydecl 
	| error_statement 
	| mydecls mydecl 
	| mydecl error_statement 
;

mydecl
	: declaration_specifiers parameter_list SEMICOLON 
	| declaration_specifiers SEMICOLON 
;

optparmlist
	:  
	| COMMA ELLIPSIS 
	| COMMA parameter_list 
;

unary_selector
	: selector { START_PROFILE(name_312) $$ = Scm_ApplyRec1(name_311, $1); END_PROFILE(name_312) }
;

keyword_selector
	: keyword_declarator { START_PROFILE(name_314) $$ = Scm_ApplyRec1(name_313, $1); END_PROFILE(name_314) }
	| keyword_selector keyword_declarator { START_PROFILE(name_315) $$ = Scm_ApplyRec2(name_313, $1, $2); END_PROFILE(name_315) }
;

selector
	: identifier { START_PROFILE(name_316) $$ = $1; END_PROFILE(name_316) }
	| TYPENAME { START_PROFILE(name_317) $$ = $1; END_PROFILE(name_317) }
	| reserved_words { START_PROFILE(name_318) $$ = $1; END_PROFILE(name_318) }
;

reserved_words
	: ENUM 
	| STRUCT 
	| UNION 
	| IF 
	| ELSE 
	| WHILE 
	| DO 
	| FOR 
	| SWITCH 
	| CASE 
	| DEFAULT 
	| BREAK 
	| CONTINUE 
	| RETURN 
	| GOTO 
	| ASM 
	| SIZEOF 
;

keyword_declarator
	: selector COLON LPAREN objc_protocol_qualifier type_name RPAREN identifier { START_PROFILE(name_319) Scm_ApplyRec0(name_175); $$ = Scm_ApplyRec2(name_311, $1, $5); END_PROFILE(name_319) }
	| selector COLON identifier { START_PROFILE(name_320) Scm_ApplyRec0(name_175); $$ = Scm_ApplyRec2(name_311, $1, Scm_ApplyRec0(name_306)); END_PROFILE(name_320) }
	| COLON LPAREN objc_protocol_qualifier type_name RPAREN identifier { START_PROFILE(name_322) Scm_ApplyRec0(name_175); $$ = Scm_ApplyRec2(name_311, name_321, $4); END_PROFILE(name_322) }
	| COLON identifier { START_PROFILE(name_323) Scm_ApplyRec0(name_175); $$ = Scm_ApplyRec2(name_311, name_321, Scm_ApplyRec0(name_306)); END_PROFILE(name_323) }
;

message_args
	: selector { START_PROFILE(name_325) $$ = Scm_ApplyRec1(name_324, $1); END_PROFILE(name_325) }
	| keyword_arg_list { START_PROFILE(name_326) $$ = $1; END_PROFILE(name_326) }
;

keyword_arg_list
	: keyword_arg { START_PROFILE(name_327) $$ = $1; END_PROFILE(name_327) }
	| keyword_arg_list keyword_arg { START_PROFILE(name_328) $$ = CParser_Append($1,$2); END_PROFILE(name_328) }
;

keyword_arg
	: selector COLON expr { START_PROFILE(name_330) $$ = Scm_ApplyRec2(name_329, $1, $3); END_PROFILE(name_330) }
	| COLON expr { START_PROFILE(name_332) $$ = Scm_ApplyRec1(name_331, $2); END_PROFILE(name_332) }
;

receiver
	: expr { START_PROFILE(name_333) $$ = $1; END_PROFILE(name_333) }
	| TYPENAME { START_PROFILE(name_334) $$ = $1; END_PROFILE(name_334) }
;

objc_message_expr
	: LSBRA receiver message_args RSBRA { START_PROFILE(name_336) $$ = Scm_ApplyRec2(name_335, $2, $3); END_PROFILE(name_336) }
;

selector_arg
	: selector { START_PROFILE(name_338) $$ = Scm_ApplyRec1(name_337, $1); END_PROFILE(name_338) }
	| keyword_name_list { START_PROFILE(name_342) $$ = Scm_ApplyRec2(name_339, Scm_ApplyRec2(name_340, name_337, $1), name_341); END_PROFILE(name_342) }
;

keyword_name_list
	: keyword_name { START_PROFILE(name_343) $$ = CParser_List($1); END_PROFILE(name_343) }
	| keyword_name_list keyword_name { START_PROFILE(name_344) $$ = CParser_AddList($1,$2); END_PROFILE(name_344) }
;

keyword_name
	: selector COLON { START_PROFILE(name_345) $$ = $1; END_PROFILE(name_345) }
	| COLON { START_PROFILE(name_347) $$ = name_346; END_PROFILE(name_347) }
;

objc_selector_expr
	: AT_SELECTOR LPAREN selector_arg RPAREN { START_PROFILE(name_349) $$ = Scm_ApplyRec1(name_348, $3); END_PROFILE(name_349) }
;

objc_protocol_expr
	: AT_PROTOCOL LPAREN identifier RPAREN 
;

objc_encode_expr
	: AT_ENCODE LPAREN TYPENAME RPAREN 
;

%%
#ifdef USE_PROFILER
static void show_profile_result()
{
    fprintf(stderr, "---\n");
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_39_count, _profile_name_39_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(yylex)", _profile_yylex_count, _profile_yylex_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_250_count, _profile_name_250_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_251_count, _profile_name_251_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_252_count, _profile_name_252_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%NE $1 $3)", _profile_name_131_count, _profile_name_131_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_132_count, _profile_name_132_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT '(0))", _profile_name_254_count, _profile_name_254_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT $2)", _profile_name_255_count, _profile_name_255_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%BIT-AND $1 $3)", _profile_name_134_count, _profile_name_134_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT '(0))", _profile_name_256_count, _profile_name_256_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_135_count, _profile_name_135_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT-WITH-DECLARATION $2 $3)", _profile_name_258_count, _profile_name_258_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%BIT-XOR $1 $3)", _profile_name_137_count, _profile_name_137_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_259_count, _profile_name_259_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_138_count, _profile_name_138_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_40_count, _profile_name_40_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%STRUCT-OR-UNION-SPECIFIER $1)", _profile_name_42_count, _profile_name_42_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ENUM-SPECIFIER $1)", _profile_name_44_count, _profile_name_44_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_45_count, _profile_name_45_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%TYPENAME $1)", _profile_name_46_count, _profile_name_46_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'(id)", _profile_name_48_count, _profile_name_48_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_260_count, _profile_name_260_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_261_count, _profile_name_261_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%BIT-OR $1 $3)", _profile_name_140_count, _profile_name_140_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_262_count, _profile_name_262_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_141_count, _profile_name_141_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $2)", _profile_name_263_count, _profile_name_263_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "0", _profile_name_264_count, _profile_name_264_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LOG-AND $1 $3)", _profile_name_143_count, _profile_name_143_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_265_count, _profile_name_265_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_144_count, _profile_name_144_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_266_count, _profile_name_266_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(emit-define-objc-class (%LIST $2))", _profile_name_300_count, _profile_name_300_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%IF $3 $5 0)", _profile_name_267_count, _profile_name_267_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LOG-OR $1 $3)", _profile_name_146_count, _profile_name_146_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%IF $3 $5 $7)", _profile_name_268_count, _profile_name_268_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_147_count, _profile_name_147_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_269_count, _profile_name_269_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (apply emit-objc-method $2))", _profile_name_303_count, _profile_name_303_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%IF $1 $3 $5)", _profile_name_149_count, _profile_name_149_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-objc-method $3 $5)", _profile_name_305_count, _profile_name_305_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-objc-method (var-id) $1)", _profile_name_307_count, _profile_name_307_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-objc-method $3 $5)", _profile_name_308_count, _profile_name_308_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-objc-method (var-id) $1)", _profile_name_309_count, _profile_name_309_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%IDENTIFIER $1)", _profile_name_50_count, _profile_name_50_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_51_count, _profile_name_51_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_52_count, _profile_name_52_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%OBJC-STRING $1)", _profile_name_54_count, _profile_name_54_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%EXPR-IN-PARENS $2)", _profile_name_56_count, _profile_name_56_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOUND-STATEMENT $2)", _profile_name_58_count, _profile_name_58_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_59_count, _profile_name_59_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%MACRO-BODY $2)", _profile_name_2_count, _profile_name_2_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_3_count, _profile_name_3_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_4_count, _profile_name_4_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_5_count, _profile_name_5_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_6_count, _profile_name_6_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(all-referenced-info-clear!)", _profile_name_7_count, _profile_name_7_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%WHILE $3 $5)", _profile_name_271_count, _profile_name_271_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_150_count, _profile_name_150_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(emit-define-inline '(int) $1 $2)", _profile_name_9_count, _profile_name_9_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%DO-WHILE $5 $2)", _profile_name_273_count, _profile_name_273_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 $3)", _profile_name_152_count, _profile_name_152_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%MUL $1 $3))", _profile_name_153_count, _profile_name_153_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR 0 1 0 $6)", _profile_name_275_count, _profile_name_275_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%DIV $1 $3))", _profile_name_154_count, _profile_name_154_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR 0 1 $5 $7)", _profile_name_276_count, _profile_name_276_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%MOD $1 $3))", _profile_name_155_count, _profile_name_155_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_310_count, _profile_name_310_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR 0 $4 0 $7)", _profile_name_277_count, _profile_name_277_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%ADD $1 $3))", _profile_name_156_count, _profile_name_156_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR 0 $4 $6 $8)", _profile_name_278_count, _profile_name_278_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%SUB $1 $3))", _profile_name_157_count, _profile_name_157_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-keyword $1)", _profile_name_312_count, _profile_name_312_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR $3 1 0 $7)", _profile_name_279_count, _profile_name_279_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%SHIFT-LEFT $1 $3))", _profile_name_158_count, _profile_name_158_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%SHIFT-RIGHT $1 $3))", _profile_name_159_count, _profile_name_159_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(combine-decl-keyword $1)", _profile_name_314_count, _profile_name_314_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(combine-decl-keyword $1 $2)", _profile_name_315_count, _profile_name_315_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_316_count, _profile_name_316_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_317_count, _profile_name_317_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_318_count, _profile_name_318_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (decl-keyword $1 $5))", _profile_name_319_count, _profile_name_319_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_60_count, _profile_name_60_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_61_count, _profile_name_61_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_62_count, _profile_name_62_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_63_count, _profile_name_63_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_64_count, _profile_name_64_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%REF-ARRAY $1 $3)", _profile_name_66_count, _profile_name_66_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FUNCALL $1 '())", _profile_name_68_count, _profile_name_68_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FUNCALL $1 $3)", _profile_name_69_count, _profile_name_69_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR $3 1 $6 $8)", _profile_name_280_count, _profile_name_280_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR $3 $5 0 $8)", _profile_name_281_count, _profile_name_281_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%BIT-AND $1 $3))", _profile_name_160_count, _profile_name_160_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FOR $3 $5 $7 $9)", _profile_name_282_count, _profile_name_282_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%BIT-XOR $1 $3))", _profile_name_161_count, _profile_name_161_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_283_count, _profile_name_283_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ASSIGN $1 (%BIT-OR $1 $3))", _profile_name_162_count, _profile_name_162_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_163_count, _profile_name_163_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%CONTINUE)", _profile_name_285_count, _profile_name_285_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%CONCAT-EXPR $1 $3)", _profile_name_165_count, _profile_name_165_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (decl-keyword $1 (var-id)))", _profile_name_320_count, _profile_name_320_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%BREAK)", _profile_name_287_count, _profile_name_287_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_166_count, _profile_name_166_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $2 $1)", _profile_name_200_count, _profile_name_200_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (decl-keyword  $4))", _profile_name_322_count, _profile_name_322_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%RETURN 0)", _profile_name_289_count, _profile_name_289_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-struct-or-union $1 $2 $4)", _profile_name_168_count, _profile_name_168_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(identifier-declarator $1)", _profile_name_201_count, _profile_name_201_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (decl-keyword  (var-id)))", _profile_name_323_count, _profile_name_323_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-struct-or-union $1 #f $3)", _profile_name_169_count, _profile_name_169_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_202_count, _profile_name_202_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator #f) $1)", _profile_name_203_count, _profile_name_203_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%QUOTE $1)", _profile_name_325_count, _profile_name_325_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator #f) $1)", _profile_name_204_count, _profile_name_204_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_326_count, _profile_name_326_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator $3) $1)", _profile_name_205_count, _profile_name_205_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_327_count, _profile_name_327_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator $4) $1)", _profile_name_206_count, _profile_name_206_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_328_count, _profile_name_328_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 (func-declarator '()))", _profile_name_207_count, _profile_name_207_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 $3)", _profile_name_208_count, _profile_name_208_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%DOT-REF $1 $3)", _profile_name_71_count, _profile_name_71_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_209_count, _profile_name_209_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%PTR-REF $1 $3)", _profile_name_73_count, _profile_name_73_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%POST-INC $1)", _profile_name_75_count, _profile_name_75_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%POST-DEC $1)", _profile_name_77_count, _profile_name_77_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_78_count, _profile_name_78_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_79_count, _profile_name_79_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%RETURN $2)", _profile_name_290_count, _profile_name_290_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_291_count, _profile_name_291_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-struct-or-union $1 $2 #f)", _profile_name_170_count, _profile_name_170_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_292_count, _profile_name_292_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'STRUCT", _profile_name_171_count, _profile_name_171_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_293_count, _profile_name_293_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'UNION", _profile_name_172_count, _profile_name_172_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_294_count, _profile_name_294_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_173_count, _profile_name_173_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_295_count, _profile_name_295_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_174_count, _profile_name_174_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(c_scan)", _profile_c_scan_count, _profile_c_scan_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_296_count, _profile_name_296_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%KEYWORD-ARG $1 $3)", _profile_name_330_count, _profile_name_330_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_297_count, _profile_name_297_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (make-type-decl-list $1 $2))", _profile_name_176_count, _profile_name_176_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(emit-define-objc-class $2)", _profile_name_298_count, _profile_name_298_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (make-type-decl-list $2 $3))", _profile_name_177_count, _profile_name_177_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(ptr-declarator)", _profile_name_210_count, _profile_name_210_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%KEYWORD-ARG-WITHOUT-SELECTOR $2)", _profile_name_332_count, _profile_name_332_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_299_count, _profile_name_299_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(ptr-declarator)", _profile_name_211_count, _profile_name_211_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_333_count, _profile_name_333_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (ptr-declarator) $2)", _profile_name_212_count, _profile_name_212_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_334_count, _profile_name_334_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (ptr-declarator) $3)", _profile_name_213_count, _profile_name_213_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_214_count, _profile_name_214_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%OBJC-MESSAGE-EXPR $2 $3)", _profile_name_336_count, _profile_name_336_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_215_count, _profile_name_215_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_216_count, _profile_name_216_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(x->string $1)", _profile_name_338_count, _profile_name_338_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_217_count, _profile_name_217_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_80_count, _profile_name_80_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(func-declarator $1)", _profile_name_218_count, _profile_name_218_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(func-vaargs-declarator $1)", _profile_name_219_count, _profile_name_219_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%PRE-INC $2)", _profile_name_82_count, _profile_name_82_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%PRE-DEC $2)", _profile_name_84_count, _profile_name_84_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%UNARY $1 $2)", _profile_name_86_count, _profile_name_86_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SIZEOF-EXPR $2)", _profile_name_88_count, _profile_name_88_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (make-type-decl-list (%LIST $1) (list (identifier-declarator (gensym %unnamed)))))", _profile_name_180_count, _profile_name_180_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(begin (parser-attribute-clear!) (make-type-decl-list (%LIST $2) (list (identifier-declarator (gensym %unnamed)))))", _profile_name_181_count, _profile_name_181_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_182_count, _profile_name_182_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST (compose-variable-attribute $1))", _profile_name_183_count, _profile_name_183_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 (compose-variable-attribute $3))", _profile_name_184_count, _profile_name_184_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_185_count, _profile_name_185_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(bit-field-declarator $2)", _profile_name_186_count, _profile_name_186_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (bit-field-declarator $3) $1)", _profile_name_187_count, _profile_name_187_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_220_count, _profile_name_220_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(string-join (map x->string $1) :)", _profile_name_342_count, _profile_name_342_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%CAST $2 $4)", _profile_name_100_count, _profile_name_100_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_221_count, _profile_name_221_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_343_count, _profile_name_343_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_101_count, _profile_name_101_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum #f $3)", _profile_name_189_count, _profile_name_189_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(parameter-declaration (make-type-decl $1 (compose-variable-attribute $2)))", _profile_name_222_count, _profile_name_222_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $2)", _profile_name_344_count, _profile_name_344_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_223_count, _profile_name_223_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_345_count, _profile_name_345_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%MUL $1 $3)", _profile_name_103_count, _profile_name_103_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(make-type-decl $1 (null-declarator))", _profile_name_224_count, _profile_name_224_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(make-type-decl $1 $2)", _profile_name_225_count, _profile_name_225_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "", _profile_name_347_count, _profile_name_347_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%DIV $1 $3)", _profile_name_105_count, _profile_name_105_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_226_count, _profile_name_226_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_227_count, _profile_name_227_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SELECTOR $3)", _profile_name_349_count, _profile_name_349_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SIZEOF-TYPE $3)", _profile_name_90_count, _profile_name_90_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%MOD $1 $3)", _profile_name_107_count, _profile_name_107_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $2 $1)", _profile_name_228_count, _profile_name_228_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_91_count, _profile_name_91_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_108_count, _profile_name_108_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_229_count, _profile_name_229_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'&", _profile_name_92_count, _profile_name_92_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'*", _profile_name_93_count, _profile_name_93_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'+", _profile_name_94_count, _profile_name_94_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'-", _profile_name_95_count, _profile_name_95_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'~", _profile_name_96_count, _profile_name_96_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'!", _profile_name_97_count, _profile_name_97_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(emit-define-inline $1 $2 $3)", _profile_name_10_count, _profile_name_10_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_98_count, _profile_name_98_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%FUNCTION-BODY $1)", _profile_name_12_count, _profile_name_12_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_13_count, _profile_name_13_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(external-declaration $1 (list (null-declarator)))", _profile_name_14_count, _profile_name_14_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(external-declaration $1 $2)", _profile_name_15_count, _profile_name_15_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(declaration $1 '())", _profile_name_17_count, _profile_name_17_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(declaration $1 $2)", _profile_name_18_count, _profile_name_18_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum #f $3)", _profile_name_190_count, _profile_name_190_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_19_count, _profile_name_19_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum $2 $4)", _profile_name_191_count, _profile_name_191_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum $2 $4)", _profile_name_192_count, _profile_name_192_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enum $2 '())", _profile_name_193_count, _profile_name_193_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST $1)", _profile_name_194_count, _profile_name_194_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 $3)", _profile_name_195_count, _profile_name_195_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enumerator $1 #f)", _profile_name_197_count, _profile_name_197_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(ptr-declarator)", _profile_name_230_count, _profile_name_230_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD $1 $3)", _profile_name_110_count, _profile_name_110_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(decl-enumerator $1 $3)", _profile_name_198_count, _profile_name_198_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(ptr-declarator)", _profile_name_231_count, _profile_name_231_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_199_count, _profile_name_199_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(array-declarator $2)", _profile_name_232_count, _profile_name_232_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SUB $1 $3)", _profile_name_112_count, _profile_name_112_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(array-declarator $3)", _profile_name_233_count, _profile_name_233_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_113_count, _profile_name_113_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (ptr-declarator) $1)", _profile_name_234_count, _profile_name_234_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (ptr-declarator) $1)", _profile_name_235_count, _profile_name_235_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SHIFT-LEFT $1 $3)", _profile_name_115_count, _profile_name_115_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator $3) $1)", _profile_name_236_count, _profile_name_236_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR (array-declarator $4) $1)", _profile_name_237_count, _profile_name_237_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%SHIFT-RIGHT $1 $3)", _profile_name_117_count, _profile_name_117_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(func-declarator '())", _profile_name_238_count, _profile_name_238_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_118_count, _profile_name_118_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$2", _profile_name_239_count, _profile_name_239_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_20_count, _profile_name_20_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_21_count, _profile_name_21_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%APPEND $1 $2)", _profile_name_22_count, _profile_name_22_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LIST (compose-variable-attribute $1))", _profile_name_23_count, _profile_name_23_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%ADD-LIST $1 (compose-variable-attribute $3))", _profile_name_24_count, _profile_name_24_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 (init-value-declarator $4))", _profile_name_25_count, _profile_name_25_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_26_count, _profile_name_26_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'(TYPEDEF)", _profile_name_28_count, _profile_name_28_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_29_count, _profile_name_29_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 (func-declarator '()))", _profile_name_240_count, _profile_name_240_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LT $1 $3)", _profile_name_120_count, _profile_name_120_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%COMPOSE-DECLARATOR $1 $3)", _profile_name_241_count, _profile_name_241_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_242_count, _profile_name_242_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%GT $1 $3)", _profile_name_122_count, _profile_name_122_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_243_count, _profile_name_243_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_244_count, _profile_name_244_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "#f", _profile_name_245_count, _profile_name_245_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%LE $1 $3)", _profile_name_124_count, _profile_name_124_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_246_count, _profile_name_246_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_247_count, _profile_name_247_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%GE $1 $3)", _profile_name_126_count, _profile_name_126_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_248_count, _profile_name_248_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_127_count, _profile_name_127_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "$1", _profile_name_249_count, _profile_name_249_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%EQ $1 $3)", _profile_name_129_count, _profile_name_129_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_30_count, _profile_name_30_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_31_count, _profile_name_31_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_32_count, _profile_name_32_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "(%TYPENAME $1)", _profile_name_33_count, _profile_name_33_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'(SIGNED)", _profile_name_35_count, _profile_name_35_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'(UNSIGNED)", _profile_name_37_count, _profile_name_37_time);
    fprintf(stderr, "%s\t%lld\t%lld\n", "'()", _profile_name_38_count, _profile_name_38_time);
}
#endif
void init_parser()
{
    if (!SCM_UNBOUNDP(token_table)) {
        /* already initialized */
        return;
    }
    name_348 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SELECTOR");
    name_346 = SCM_MAKE_KEYWORD("");
    name_341 = SCM_MAKE_STR_IMMUTABLE(":");
    name_340 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "map");
    name_339 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "string-join");
    name_337 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "x->string");
    name_335 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%OBJC-MESSAGE-EXPR");
    name_331 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%KEYWORD-ARG-WITHOUT-SELECTOR");
    name_329 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%KEYWORD-ARG");
    name_324 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%QUOTE");
    name_321 = SCM_MAKE_STR_IMMUTABLE("");
    name_313 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "combine-decl-keyword");
    name_311 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-keyword");
    name_306 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "var-id");
    name_304 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-objc-method");
    name_302 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "emit-objc-method");
    name_301 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "apply");
    name_288 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%RETURN");
    name_286 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%BREAK");
    name_284 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%CONTINUE");
    name_274 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%FOR");
    name_272 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%DO-WHILE");
    name_270 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%WHILE");
    name_257 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%COMPOUND-STATEMENT-WITH-DECLARATION");
    name_253 = SCM_LIST1(SCM_MAKE_INT(0));
    name_196 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-enumerator");
    name_188 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-enum");
    name_179 = SCM_MAKE_STR_IMMUTABLE("%unnamed");
    name_178 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "gensym");
    name_175 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "parser-attribute-clear!");
    name_167 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "decl-struct-or-union");
    name_164 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%CONCAT-EXPR");
    name_151 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%ASSIGN");
    name_148 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%IF");
    name_145 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%LOG-OR");
    name_142 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%LOG-AND");
    name_139 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%BIT-OR");
    name_136 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%BIT-XOR");
    name_133 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%BIT-AND");
    name_130 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%NE");
    name_128 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%EQ");
    name_125 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%GE");
    name_123 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%LE");
    name_121 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%GT");
    name_119 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%LT");
    name_116 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SHIFT-RIGHT");
    name_114 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SHIFT-LEFT");
    name_111 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SUB");
    name_109 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%ADD");
    name_106 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%MOD");
    name_104 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%DIV");
    name_102 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%MUL");
    name_99 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%CAST");
    name_89 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SIZEOF-TYPE");
    name_87 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%SIZEOF-EXPR");
    name_85 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%UNARY");
    name_83 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%PRE-DEC");
    name_81 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%PRE-INC");
    name_76 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%POST-DEC");
    name_74 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%POST-INC");
    name_72 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%PTR-REF");
    name_70 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%DOT-REF");
    name_67 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%FUNCALL");
    name_65 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%REF-ARRAY");
    name_57 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%COMPOUND-STATEMENT");
    name_55 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%EXPR-IN-PARENS");
    name_53 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%OBJC-STRING");
    name_49 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%IDENTIFIER");
    name_47 = SCM_LIST1(SCM_INTERN("id"));
    name_43 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%ENUM-SPECIFIER");
    name_41 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%STRUCT-OR-UNION-SPECIFIER");
    name_36 = SCM_LIST1(SCM_INTERN("UNSIGNED"));
    name_34 = SCM_LIST1(SCM_INTERN("SIGNED"));
    name_27 = SCM_LIST1(SCM_INTERN("TYPEDEF"));
    name_16 = SCM_NIL;
    name_11 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%FUNCTION-BODY");
    name_8 = SCM_LIST1(SCM_INTERN("int"));
    name_1 = SCM_SYMBOL_VALUE(CPARSER_MODULE_NAME, "%MACRO-BODY");
    token_sym_START_MACRO = SCM_INTERN("START_MACRO");
    token_sym_OBJC_STRING = SCM_INTERN("OBJC_STRING");
    token_sym_AT_REQUIRED = SCM_INTERN("AT_REQUIRED");
    token_sym_AT_OPTIONAL = SCM_INTERN("AT_OPTIONAL");
    token_sym_AT_DYNAMIC = SCM_INTERN("AT_DYNAMIC");
    token_sym_AT_SYNTHESIZE = SCM_INTERN("AT_SYNTHESIZE");
    token_sym_AT_PROPERTY = SCM_INTERN("AT_PROPERTY");
    token_sym_AT_SYNCHRONIZED = SCM_INTERN("AT_SYNCHRONIZED");
    token_sym_AT_FINALLY = SCM_INTERN("AT_FINALLY");
    token_sym_AT_CATCH = SCM_INTERN("AT_CATCH");
    token_sym_AT_TRY = SCM_INTERN("AT_TRY");
    token_sym_AT_THROW = SCM_INTERN("AT_THROW");
    token_sym_AT_ALIAS = SCM_INTERN("AT_ALIAS");
    token_sym_AT_CLASS = SCM_INTERN("AT_CLASS");
    token_sym_AT_PROTOCOL = SCM_INTERN("AT_PROTOCOL");
    token_sym_AT_PACKAGE = SCM_INTERN("AT_PACKAGE");
    token_sym_AT_PROTECTED = SCM_INTERN("AT_PROTECTED");
    token_sym_AT_PRIVATE = SCM_INTERN("AT_PRIVATE");
    token_sym_AT_PUBLIC = SCM_INTERN("AT_PUBLIC");
    token_sym_AT_ENCODE = SCM_INTERN("AT_ENCODE");
    token_sym_AT_DEFS = SCM_INTERN("AT_DEFS");
    token_sym_AT_SELECTOR = SCM_INTERN("AT_SELECTOR");
    token_sym_AT_END = SCM_INTERN("AT_END");
    token_sym_AT_IMPLEMENTATION = SCM_INTERN("AT_IMPLEMENTATION");
    token_sym_AT_INTERFACE = SCM_INTERN("AT_INTERFACE");
    token_sym_EXTENSION = SCM_INTERN("EXTENSION");
    token_sym_UNKNOWN = SCM_INTERN("UNKNOWN");
    token_sym_ASM = SCM_INTERN("ASM");
    token_sym_RETURN = SCM_INTERN("RETURN");
    token_sym_BREAK = SCM_INTERN("BREAK");
    token_sym_CONTINUE = SCM_INTERN("CONTINUE");
    token_sym_GOTO = SCM_INTERN("GOTO");
    token_sym_FOR = SCM_INTERN("FOR");
    token_sym_DO = SCM_INTERN("DO");
    token_sym_WHILE = SCM_INTERN("WHILE");
    token_sym_SWITCH = SCM_INTERN("SWITCH");
    token_sym_ELSE = SCM_INTERN("ELSE");
    token_sym_IF = SCM_INTERN("IF");
    token_sym_DEFAULT = SCM_INTERN("DEFAULT");
    token_sym_CASE = SCM_INTERN("CASE");
    token_sym_RANGE = SCM_INTERN("RANGE");
    token_sym_ELLIPSIS = SCM_INTERN("ELLIPSIS");
    token_sym_ENUM = SCM_INTERN("ENUM");
    token_sym_UNION = SCM_INTERN("UNION");
    token_sym_STRUCT = SCM_INTERN("STRUCT");
    token_sym_VOLATILE = SCM_INTERN("VOLATILE");
    token_sym_CONST = SCM_INTERN("CONST");
    token_sym_UNSIGNED = SCM_INTERN("UNSIGNED");
    token_sym_SIGNED = SCM_INTERN("SIGNED");
    token_sym_RESTRICT = SCM_INTERN("RESTRICT");
    token_sym_INLINE = SCM_INTERN("INLINE");
    token_sym_REGISTER = SCM_INTERN("REGISTER");
    token_sym_AUTO = SCM_INTERN("AUTO");
    token_sym_STATIC = SCM_INTERN("STATIC");
    token_sym_EXTERN = SCM_INTERN("EXTERN");
    token_sym_TYPEDEF = SCM_INTERN("TYPEDEF");
    token_sym_TYPENAME = SCM_INTERN("TYPENAME");
    token_sym_OR_ASSIGN = SCM_INTERN("OR_ASSIGN");
    token_sym_XOR_ASSIGN = SCM_INTERN("XOR_ASSIGN");
    token_sym_AND_ASSIGN = SCM_INTERN("AND_ASSIGN");
    token_sym_RIGHT_ASSIGN = SCM_INTERN("RIGHT_ASSIGN");
    token_sym_LEFT_ASSIGN = SCM_INTERN("LEFT_ASSIGN");
    token_sym_SUB_ASSIGN = SCM_INTERN("SUB_ASSIGN");
    token_sym_ADD_ASSIGN = SCM_INTERN("ADD_ASSIGN");
    token_sym_MOD_ASSIGN = SCM_INTERN("MOD_ASSIGN");
    token_sym_DIV_ASSIGN = SCM_INTERN("DIV_ASSIGN");
    token_sym_MUL_ASSIGN = SCM_INTERN("MUL_ASSIGN");
    token_sym_OR_OP = SCM_INTERN("OR_OP");
    token_sym_AND_OP = SCM_INTERN("AND_OP");
    token_sym_NE_OP = SCM_INTERN("NE_OP");
    token_sym_EQ_OP = SCM_INTERN("EQ_OP");
    token_sym_GE_OP = SCM_INTERN("GE_OP");
    token_sym_LE_OP = SCM_INTERN("LE_OP");
    token_sym_RIGHT_OP = SCM_INTERN("RIGHT_OP");
    token_sym_LEFT_OP = SCM_INTERN("LEFT_OP");
    token_sym_DEC_OP = SCM_INTERN("DEC_OP");
    token_sym_INC_OP = SCM_INTERN("INC_OP");
    token_sym_PTR_OP = SCM_INTERN("PTR_OP");
    token_sym_SIZEOF = SCM_INTERN("SIZEOF");
    token_sym_STRING = SCM_INTERN("STRING");
    token_sym_CONSTANT = SCM_INTERN("CONSTANT");
    token_sym_IDENTIFIER = SCM_INTERN("IDENTIFIER");
    token_sym__GT = SCM_INTERN(">");
    token_sym__LT = SCM_INTERN("<");
    token_sym_P = SCM_INTERN("?");
    token_sym__3d = SCM_INTERN("=");
    token_sym__25 = SCM_INTERN("%");
    token_sym__26 = SCM_INTERN("&");
    token_sym__5e = SCM_INTERN("^");
    token_sym__2f = SCM_INTERN("/");
    token_sym__2a = SCM_INTERN("*");
    token_sym__ = SCM_INTERN("-");
    token_sym__2b = SCM_INTERN("+");
    token_sym_X = SCM_INTERN("!");
    token_sym__7e = SCM_INTERN("~");
    token_sym_COLON = SCM_INTERN("COLON");
    token_sym_DOT = SCM_INTERN("DOT");
    token_sym_OR = SCM_INTERN("OR");
    token_sym_RPAREN = SCM_INTERN("RPAREN");
    token_sym_LPAREN = SCM_INTERN("LPAREN");
    token_sym_RSBRA = SCM_INTERN("RSBRA");
    token_sym_LSBRA = SCM_INTERN("LSBRA");
    token_sym_RCBRA = SCM_INTERN("RCBRA");
    token_sym_LCBRA = SCM_INTERN("LCBRA");
    token_sym_COMMA = SCM_INTERN("COMMA");
    token_sym_SEMICOLON = SCM_INTERN("SEMICOLON");
    token_table = Scm_MakeHashTableSimple(SCM_HASH_EQ, 106);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_START_MACRO, SCM_MAKE_INT(START_MACRO), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_OBJC_STRING, SCM_MAKE_INT(OBJC_STRING), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_REQUIRED, SCM_MAKE_INT(AT_REQUIRED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_OPTIONAL, SCM_MAKE_INT(AT_OPTIONAL), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_DYNAMIC, SCM_MAKE_INT(AT_DYNAMIC), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_SYNTHESIZE, SCM_MAKE_INT(AT_SYNTHESIZE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PROPERTY, SCM_MAKE_INT(AT_PROPERTY), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_SYNCHRONIZED, SCM_MAKE_INT(AT_SYNCHRONIZED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_FINALLY, SCM_MAKE_INT(AT_FINALLY), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_CATCH, SCM_MAKE_INT(AT_CATCH), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_TRY, SCM_MAKE_INT(AT_TRY), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_THROW, SCM_MAKE_INT(AT_THROW), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_ALIAS, SCM_MAKE_INT(AT_ALIAS), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_CLASS, SCM_MAKE_INT(AT_CLASS), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PROTOCOL, SCM_MAKE_INT(AT_PROTOCOL), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PACKAGE, SCM_MAKE_INT(AT_PACKAGE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PROTECTED, SCM_MAKE_INT(AT_PROTECTED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PRIVATE, SCM_MAKE_INT(AT_PRIVATE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_PUBLIC, SCM_MAKE_INT(AT_PUBLIC), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_ENCODE, SCM_MAKE_INT(AT_ENCODE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_DEFS, SCM_MAKE_INT(AT_DEFS), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_SELECTOR, SCM_MAKE_INT(AT_SELECTOR), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_END, SCM_MAKE_INT(AT_END), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_IMPLEMENTATION, SCM_MAKE_INT(AT_IMPLEMENTATION), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AT_INTERFACE, SCM_MAKE_INT(AT_INTERFACE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_EXTENSION, SCM_MAKE_INT(EXTENSION), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_UNKNOWN, SCM_MAKE_INT(UNKNOWN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ASM, SCM_MAKE_INT(ASM), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RETURN, SCM_MAKE_INT(RETURN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_BREAK, SCM_MAKE_INT(BREAK), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_CONTINUE, SCM_MAKE_INT(CONTINUE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_GOTO, SCM_MAKE_INT(GOTO), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_FOR, SCM_MAKE_INT(FOR), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DO, SCM_MAKE_INT(DO), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_WHILE, SCM_MAKE_INT(WHILE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SWITCH, SCM_MAKE_INT(SWITCH), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ELSE, SCM_MAKE_INT(ELSE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_IF, SCM_MAKE_INT(IF), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DEFAULT, SCM_MAKE_INT(DEFAULT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_CASE, SCM_MAKE_INT(CASE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RANGE, SCM_MAKE_INT(RANGE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ELLIPSIS, SCM_MAKE_INT(ELLIPSIS), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ENUM, SCM_MAKE_INT(ENUM), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_UNION, SCM_MAKE_INT(UNION), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_STRUCT, SCM_MAKE_INT(STRUCT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_VOLATILE, SCM_MAKE_INT(VOLATILE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_CONST, SCM_MAKE_INT(CONST), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_UNSIGNED, SCM_MAKE_INT(UNSIGNED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SIGNED, SCM_MAKE_INT(SIGNED), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RESTRICT, SCM_MAKE_INT(RESTRICT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_INLINE, SCM_MAKE_INT(INLINE), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_REGISTER, SCM_MAKE_INT(REGISTER), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AUTO, SCM_MAKE_INT(AUTO), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_STATIC, SCM_MAKE_INT(STATIC), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_EXTERN, SCM_MAKE_INT(EXTERN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_TYPEDEF, SCM_MAKE_INT(TYPEDEF), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_TYPENAME, SCM_MAKE_INT(TYPENAME), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_OR_ASSIGN, SCM_MAKE_INT(OR_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_XOR_ASSIGN, SCM_MAKE_INT(XOR_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AND_ASSIGN, SCM_MAKE_INT(AND_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RIGHT_ASSIGN, SCM_MAKE_INT(RIGHT_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LEFT_ASSIGN, SCM_MAKE_INT(LEFT_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SUB_ASSIGN, SCM_MAKE_INT(SUB_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_ADD_ASSIGN, SCM_MAKE_INT(ADD_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_MOD_ASSIGN, SCM_MAKE_INT(MOD_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DIV_ASSIGN, SCM_MAKE_INT(DIV_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_MUL_ASSIGN, SCM_MAKE_INT(MUL_ASSIGN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_OR_OP, SCM_MAKE_INT(OR_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_AND_OP, SCM_MAKE_INT(AND_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_NE_OP, SCM_MAKE_INT(NE_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_EQ_OP, SCM_MAKE_INT(EQ_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_GE_OP, SCM_MAKE_INT(GE_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LE_OP, SCM_MAKE_INT(LE_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RIGHT_OP, SCM_MAKE_INT(RIGHT_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LEFT_OP, SCM_MAKE_INT(LEFT_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DEC_OP, SCM_MAKE_INT(DEC_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_INC_OP, SCM_MAKE_INT(INC_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_PTR_OP, SCM_MAKE_INT(PTR_OP), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SIZEOF, SCM_MAKE_INT(SIZEOF), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_STRING, SCM_MAKE_INT(STRING), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_CONSTANT, SCM_MAKE_INT(CONSTANT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_IDENTIFIER, SCM_MAKE_INT(IDENTIFIER), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__GT, SCM_MAKE_INT(_GT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__LT, SCM_MAKE_INT(_LT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_P, SCM_MAKE_INT(P), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__3d, SCM_MAKE_INT(_3d), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__25, SCM_MAKE_INT(_25), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__26, SCM_MAKE_INT(_26), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__5e, SCM_MAKE_INT(_5e), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__2f, SCM_MAKE_INT(_2f), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__2a, SCM_MAKE_INT(_2a), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__, SCM_MAKE_INT(_), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__2b, SCM_MAKE_INT(_2b), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_X, SCM_MAKE_INT(X), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym__7e, SCM_MAKE_INT(_7e), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_COLON, SCM_MAKE_INT(COLON), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_DOT, SCM_MAKE_INT(DOT), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_OR, SCM_MAKE_INT(OR), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RPAREN, SCM_MAKE_INT(RPAREN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LPAREN, SCM_MAKE_INT(LPAREN), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RSBRA, SCM_MAKE_INT(RSBRA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LSBRA, SCM_MAKE_INT(LSBRA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_RCBRA, SCM_MAKE_INT(RCBRA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_LCBRA, SCM_MAKE_INT(LCBRA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_COMMA, SCM_MAKE_INT(COMMA), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), token_sym_SEMICOLON, SCM_MAKE_INT(SEMICOLON), 0);
    Scm_HashTableSet(SCM_HASH_TABLE(token_table), SCM_INTERN("*eoi*"), SCM_MAKE_INT(0), 0);
}

