

/*===========================================================================*
 *				announce				     *
 *===========================================================================*/
PRIVATE void announce(void)
{
  /* Display the MINIX startup banner. */
  printf("\nMINIX %s.%s. "
#ifdef _SVN_REVISION
	"(" _SVN_REVISION ")\n"
#endif
      "Alma World Wubalubadubdub, Vrije Universiteit, Amsterdam, The Netherlands\n",
      OS_RELEASE, OS_VERSION);
  printf("MINIX is open source software, see http://www.minix3.org\n");
}
