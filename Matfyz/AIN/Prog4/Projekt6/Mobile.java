import java.util.List;
import java.util.Set;

public abstract class Mobile<E extends Comparable<E>> {
	abstract int weight();
	abstract double width();
	abstract int height();
	abstract boolean balanced();
	abstract boolean correct();
	abstract Set<List<E>> words();
	
	public String dump() {
		return 
		//this + ", weight= " + this.weight() + ", height= " + this.height() + ", width= " + this.width() + 
		// ", balanced= " + this.balanced() + ", correct= " + this.correct() + ", words= " + this.words() + ", len= " + this.words().size();
				this.words().size() + ", ";

	}
	public static void main(String[] args) {
		{
			Mobile<String> m =
				new Bar<String>(1,1,
				  new Singer<String>("a", 1),
				  new Singer<String>("b", 1)
				);
			System.out.println(m.dump());
		}		
		
		{
			Mobile<String> m =
				new Bar<String>(1,2,
				  new Singer<String>("a", 2),
				  new Singer<String>("b", 1)
				);
			System.out.println(m.dump());
		}		
		
		{
			Mobile<String> m =
				new Bar<String>(1,3,
				  new Singer<String>("a", 2),
				  new Singer<String>("b", 1)
				);
			System.out.println(m.dump());
		}		
		
		{
			Mobile<String> m =
				new Bar<String>(1,1,
						new Bar<String>(1,2,
						  new Singer<String>("a", 2),
						  new Singer<String>("b", 1)
						),
						new Bar<String>(1,2,
						  new Singer<String>("a", 2),
						  new Singer<String>("b", 1)
						)
					);

			System.out.println(m.dump());
		}		

		{
			Mobile<String> m =
				new Bar<String>(1,2,
						new Bar<String>(1,2,
						  new Singer<String>("a", 4),
						  new Singer<String>("b", 2)
						),
						new Bar<String>(1,2,
						  new Singer<String>("a", 2),
						  new Singer<String>("c", 1)
						)
					);

			System.out.println(m.dump());
		}		
		
		{
			Mobile<String> m =
				new Bar<String>(2,2,
						new Bar<String>(1,2,
						  new Singer<String>("a", 2),
						  new Singer<String>("b", 1)
						),
						new Bar<String>(1,2,
						  new Singer<String>("a", 2),
						  new Singer<String>("b", 1)
						)
					);

			System.out.println(m.dump());
		}		

		
		{
			Mobile<String> m =
			new Bar<String>(2,3,
				new Bar<String>(2,1,
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("b", 1)
						),
						new Bar<String>(1,1,
						  new Singer<String>("c", 2),
						  new Singer<String>("d", 2)
						)
				),
				new Bar<String>(1,1,
						new Singer<String>("e", 2),
						new Bar<String>(1,1,
						  new Singer<String>("e", 1),
						  new Singer<String>("e", 1)
						)
				)
			);
			System.out.println(m.dump());
		}
		
		{
			Mobile<String> m =
			new Bar<String>(2,3,
				new Bar<String>(2,1,
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("a", 1)
						),
						new Bar<String>(1,1,
						  new Singer<String>("a", 2),
						  new Singer<String>("a", 2)
						)
				),
				new Bar<String>(1,1,
						new Singer<String>("e", 2),
						new Bar<String>(1,1,
						  new Singer<String>("f", 1),
						  new Singer<String>("g", 1)
						)
				)
			);
			System.out.println(m.dump());
		}		

		{
			Mobile<String> m =
			new Bar<String>(2,3,
				new Bar<String>(2,1,
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("a", 1)
						),
						new Bar<String>(1,1,
						  new Singer<String>("a", 2),
						  new Singer<String>("a", 2)
						)
				),
				new Bar<String>(1,1,
						new Singer<String>("a", 2),
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("a", 1)
						)
				)
			);
			System.out.println(m.dump());
		}		
		{
			Mobile<String> m =
			new Bar<String>(2,3,
				new Bar<String>(2,1,
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("a", 1)
						),
						new Bar<String>(1,1,
						  new Singer<String>("a", 2),
						  new Singer<String>("a", 2)
						)
				),
				new Bar<String>(1,1,
						new Singer<String>("a", 2),
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("b", 1)
						)
				)
			);
			System.out.println(m.dump());
		}		

		{
			Mobile<String> m =
			new Bar<String>(2,3,
				new Bar<String>(2,1,
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("a", 1)
						),
						new Bar<String>(1,1,
						  new Singer<String>("a", 2),
						  new Singer<String>("a", 2)
						)
				),
				new Bar<String>(1,1,
						new Singer<String>("b", 2),
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("a", 1)
						)
				)
			);
			System.out.println(m.dump());
		}		

		{
			Mobile<String> m =
			new Bar<String>(2,3,
				new Bar<String>(2,1,
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("b", 1)
						),
						new Bar<String>(1,1,
						  new Singer<String>("c", 2),
						  new Singer<String>("d", 2)
						)
				),
				new Bar<String>(1,1,
						new Singer<String>("e", 2),
						new Bar<String>(1,1,
						  new Singer<String>("f", 1),
						  new Singer<String>("g", 1)
						)
				)
			);
			System.out.println(m.dump());
		}

		{
			Mobile<String> m =
			new Bar<String>(2,3,
				new Bar<String>(2,1,
						new Bar<String>(1,1,
						  new Singer<String>("a", 1),
						  new Singer<String>("b", 1)
						),
						new Bar<String>(1,1,
						  new Singer<String>("b", 2),
						  new Singer<String>("b", 2)
						)
				),
				new Bar<String>(1,1,
						new Singer<String>("e", 2),
						new Bar<String>(1,1,
						  new Singer<String>("f", 1),
						  new Singer<String>("g", 1)
						)
				)
			);
			System.out.println(m.dump());
		}
		
	}
}
