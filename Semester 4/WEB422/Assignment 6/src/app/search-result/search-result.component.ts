import { Component, OnDestroy, OnInit } from '@angular/core';
import { ActivatedRoute, Params } from '@angular/router';
import { MusicDataService } from '../music-data.service';
import { Subscription } from 'rxjs';

@Component({
  selector: 'app-search-result',
  templateUrl: './search-result.component.html',
  styleUrls: ['./search-result.component.css']
})
export class SearchResultComponent implements OnInit, OnDestroy {

  results: any;
  searchQuery: string = "";
  searchSub: any;

  constructor(private route: ActivatedRoute, private musicDataService: MusicDataService) {}

  ngOnInit(): void {
    this.searchSub = this.route.queryParams.subscribe((params) => {
      this.searchQuery = params['q'];
      this.musicDataService.searchArtists(this.searchQuery).subscribe((data) => {
          this.results = data.artists.items.filter(
              (artist: any) => artist.images.length > 0
            );
        });
      }
    );
  }

  ngOnDestroy(): void {
    this.searchSub?.unsubscribe();
  }
}
