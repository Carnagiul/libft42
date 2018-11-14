



int			ft_xml_init_parser(char *file)
{
	xmlDoc	*doc;
	xmlNode	*root;

	root = NULL;
	if (!(root = ft_initial_pars(&doc, root, file)))
		return (-1);
	if (pars_content(root) == -1)
		return (-1);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	ft_printf("\n");
	return (0);
}