/*----------------------------------------------------------------------------
 * File:  ooaofooa_population_class.c
 *
 * Class:       population  (population)
 * Component:   ooaofooa
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "sys_sys_types.h"
#include "LOG_bridge.h"
#include "LOG_bridge.h"
#include "POP_bridge.h"
#include "STRING_bridge.h"
#include "STRING_bridge.h"
#include "T_bridge.h"
#include "T_bridge.h"
#include "TRACE_bridge.h"
#include "TRACE_bridge.h"
#include "ooaofooa_classes.h"

/*
 * Instance Loader (from string data).
 */
Escher_iHandle_t
ooaofooa_population_instanceloader( Escher_iHandle_t instance, const c_t * avlstring[] )
{
  Escher_iHandle_t return_identifier = 0;
  ooaofooa_population * self = (ooaofooa_population *) instance;
  /* Initialize application analysis class attributes.  */
  Escher_memset( &self->project, 4, sizeof( self->project ) );
  Escher_memset( &self->domain, 4, sizeof( self->domain ) );
  Escher_memset( &self->object, 4, sizeof( self->object ) );
  Escher_memset( &self->terminator, 4, sizeof( self->terminator ) );
  Escher_memset( &self->activity, 4, sizeof( self->activity ) );
  Escher_memset( &self->parameter, 4, sizeof( self->parameter ) );
  Escher_memset( &self->attribute, 4, sizeof( self->attribute ) );
  return return_identifier;
}

/*
 * class operation:  populate
 */
void
ooaofooa_population_op_populate( c_t * p_element, c_t * p_value[8] )
{
  c_t * value[8]={0,0,0,0,0,0,0,0};c_t * element=0;ooaofooa_population * population=0;
int i;
printf("%s",p_element);
for(i=0;i<8;i++) { if (p_value[i]) { printf(",%s",p_value[i]); } else { break; }}
printf("\n");
  /* ASSIGN element = PARAM.element */
  element = Escher_strcpy( element, p_element );
  /* ASSIGN value = PARAM.value */
  value[0] = p_value[0];
  value[1] = p_value[1];
  value[2] = p_value[2];
  value[3] = p_value[3];
  /* SELECT any population FROM INSTANCES OF population */
  population = (ooaofooa_population *) Escher_SetGetAny( &pG_ooaofooa_population_extent.active );
  /* IF ( empty population ) */
  if ( ( 0 == population ) ) {
    /* CREATE OBJECT INSTANCE population OF population */
    population = (ooaofooa_population *) Escher_CreateInstance( ooaofooa_DOMAIN_ID, ooaofooa_population_CLASS_NUMBER );
  }
  /* IF ( ( project == element ) ) */
  if ( ( Escher_strcmp( "project", element ) == 0 ) ) {
    /* ASSIGN population.project = project::populate(name:value[0]) */
    population->project = ooaofooa_project_op_populate(value[0]);
  }
  else if ( ( Escher_strcmp( "domain", element ) == 0 ) ) {
    /* ASSIGN population.domain = domain::populate(name:value[0], project:population.project) */
    population->domain = ooaofooa_domain_op_populate(value[0], population->project);
  }
  else if ( ( Escher_strcmp( "object", element ) == 0 ) ) {
    /* ASSIGN population.object = object::populate(domain:population.domain, name:value[0]) */
    population->object = ooaofooa_object_op_populate(population->domain, value[0]);
  }
  else if ( ( Escher_strcmp( "terminator", element ) == 0 ) ) {
    /* ASSIGN population.terminator = terminator::populate(domain:population.domain, name:value[0]) */
    population->terminator = ooaofooa_terminator_op_populate(population->domain, value[0]);
  }
  else if ( ( Escher_strcmp( "activity", element ) == 0 ) ) {
    /* IF ( (  != value[1] ) ) */
    if ( ( Escher_strcmp( "", value[1] ) != 0 ) ) {
      /* ASSIGN population.activity = activity::populate(flavor:value[2], name:value[0], terminator:population.terminator) */
      population->activity = ooaofooa_activity_op_populate(value[2], value[0], population->terminator);
    }
    else if ( FALSE ) {
    }
    else if ( FALSE ) {
    }
    else {
      /* TRACE::log( flavor:failure, id:40, message:( unrecognized activity:   + value[0] ) ) */
      TRACE_log( "failure", 40, Escher_stradd( "unrecognized activity:  ", value[0] ) );
    }
  }
  else if ( ( Escher_strcmp( "parameter", element ) == 0 ) ) {
    /* IF ( (  == value[3] ) ) */
    if ( ( Escher_strcmp( "", value[3] ) == 0 ) ) {
      ooaofooa_parameter * empty_parameter=0;
      /* SELECT any empty_parameter FROM INSTANCES OF parameter WHERE FALSE */
      empty_parameter = 0;
      /* ASSIGN population.parameter = parameter::populate(activity:population.activity, direction:value[2], name:value[0], previous_parameter:empty_parameter, type:value[1]) */
      population->parameter = ooaofooa_parameter_op_populate(population->activity, value[2], value[0], empty_parameter, value[1]);
    }
    else {
      /* ASSIGN population.parameter = parameter::populate(activity:population.activity, direction:value[2], name:value[0], previous_parameter:population.parameter, type:value[1]) */
      population->parameter = ooaofooa_parameter_op_populate(population->activity, value[2], value[0], population->parameter, value[1]);
    }
  }
  else if ( ( Escher_strcmp( "attribute", element ) == 0 ) ) {
    /* ASSIGN population.attribute = attribute::populate(defaultvalue:value[3], name:value[0], object:population.object, preferred:value[1], unique:value[2]) */
    population->attribute = ooaofooa_attribute_op_populate(value[3], value[0], population->object, value[1], value[2]);
  }
  else {
    /* TRACE::log( flavor:failure, id:39, message:( unrecognized element:   + element ) ) */
    TRACE_log( "failure", 39, Escher_stradd( "unrecognized element:  ", element ) );
  }
}

/*
 * Dump instances in SQL format.
 */
void
ooaofooa_population_instancedumper( Escher_iHandle_t instance )
{
  ooaofooa_population * self = (ooaofooa_population *) instance;
}

/*----------------------------------------------------------------------------
 * Operation action methods implementation for the following class:
 *
 * Class:      population  (population)
 * Component:  ooaofooa
 *--------------------------------------------------------------------------*/
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ooaofooa_population_container[ ooaofooa_population_MAX_EXTENT_SIZE ];
static ooaofooa_population ooaofooa_population_instances[ ooaofooa_population_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ooaofooa_population_extent = {
  {0,0}, {0,0}, &ooaofooa_population_container[ 0 ],
  (Escher_iHandle_t) &ooaofooa_population_instances,
  sizeof( ooaofooa_population ), 0, ooaofooa_population_MAX_EXTENT_SIZE
  };
